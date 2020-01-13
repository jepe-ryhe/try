#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int len = A[0].length();
    vector<int> dp(len, 1);
    int max = 1;
    for (int i = 1; i < len; i++) {
      int ii = len - 1 - i;
      for (int j = ii + 1; j < len; j++) {
        if (dp.at(j) < dp.at(ii))
          continue;
        if (all_of(A.begin(), A.end(),
                   [=](auto s) { return s.at(j) >= s.at(ii); })) {
          dp.at(ii) = dp.at(j) + 1;
          if (dp.at(ii) > max) {
            max = dp.at(ii);
          }
        }
      }
    }
    return len - max;
  }
};

int main() {
  Solution solution;
  vector<string> s = {"babca", "bbazb"};
  auto result = solution.minDeletionSize(s);
  cout << result;
}