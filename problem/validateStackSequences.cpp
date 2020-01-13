#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    auto f = pushed.cbegin();
    for (const auto ch : popped) {
      if (!s.empty() && s.top() == ch) {
        s.pop();
      } else {
        while (f != pushed.cend() && *f != ch) {
          s.push(*f++);
        }
        if (f == pushed.cend())
          return false;
        else
          f++;
      }
    }
    return f == pushed.cend();
  }
};

int main() {
  Solution solution;
  vector<int> pu = {1, 2, 3, 4, 5}, po = {4, 5, 3, 2, 1};
  auto result = solution.validateStackSequences(pu, po);
  cout << result;
}