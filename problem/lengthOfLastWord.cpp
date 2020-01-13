#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    if (s.length() == 0)
      return 0;
    int len = 0, c = 0, l = s.length();
    for (int i = 0; i < l; i++) {
      if (s[i] != ' ') {
        len++;
      } else {
        c = len == 0 ? c : len;
        len = 0;
      }
    }
    if (len == 0) {
      return c;
    } else {
      return len;
    }
  }
};

int main() {
  Solution solution;
  string s = "b a  ";
  auto result = solution.lengthOfLastWord(s);
  cout << result;
}