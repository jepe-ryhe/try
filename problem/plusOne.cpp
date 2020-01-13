#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 9) {
        digits[i] = 0;
      } else {
        digits[i]++;
        break;
      }
    }
    if (digits[0] == 0) {
      digits.push_back(0);
      digits[0] = 1;
    }
    return digits;
  }
};

int main() {
  Solution solution;
  vector<int> n = {1, 2, 3};
  auto result = solution.plusOne(n);
  for (auto &&i : result) {
    cout << i << ' ';
  }
}