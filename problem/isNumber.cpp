#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Solution {
public:
  bool isNumber(string s) {
    regex r("^\\s*[\\+-]?((\\d+(\\.\\d*)?)|\\.\\d+)([eE][\\+-]?\\d+)?\\s*$");
    return regex_match(s, r);
  }
};

int main() {
  Solution solution;
  string s = " 99e2.5 ";
  auto result = solution.isNumber(s);
  cout << result;
}