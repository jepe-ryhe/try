#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (s.length() == 0) {
      return 0;
    }
    int len = s.length();

    int help = 1;
    int res = 0;
    if (s.at(len - 1) != '0') {
      res = 1;
    }
    for (int i = len - 2; i >= 0; i--) {
      if (s.at(i) == '0') {
        help = res;
        res = 0;
        continue;
      }
      if ((s.at(i) - '0') * 10 + (s.at(i + 1) - '0') <= 26) {
        res += help;
        help = res - help;
      } else {
        help = res;
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  string s = "226";
  auto result = solution.numDecodings(s);
  cout << result;
}