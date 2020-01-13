#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0)
      return {""};
    if (n == 1)
      return {"()"};
    unordered_map<int, vector<string>> map;
    map[0] = {""};
    map[1] = {"()"};
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        for (auto &&s1 : map[j]) {
          for (auto &&s2 : map[i - j - 1]) {
            map[i].push_back("(" + s1 + ")" + s2);
          }
        }
      }
    }
    return map[n];
  }
};

int main() {
  Solution solution;
  auto result = solution.generateParenthesis(3);
  for (auto &&i : result) {
    cout << i << endl;
  }
}