#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    int l1 = num1.length(), l2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string res;
    for (int i1 = 0; i1 < l1; i1++) {
      string m;
      int succ = 0;
      for (int i2 = 0; i2 < l2; i2++) {
        int tmp = (num1[i1] - '0') * (num2[i2] - '0') + succ;
        m.push_back(tmp % 10 + '0');
        succ = tmp / 10;
      }
      while (succ != 0) {
        m.push_back(succ % 10 + '0');
        succ /= 10;
      }
      int lm = m.length();
      for (int i = 0; i < lm; i++) {
        int tmp =
            (res[i + i1] > '0' ? res[i + i1] - '0' : 0) + (m[i] - '0') + succ;
        if (res[i + i1] >= '0')
          res[i + i1] = tmp % 10 + '0';
        else
          res.push_back(tmp % 10 + '0');
        // res[i + i1] > '0' ? res[i + i1] = tmp % 10 + '0' : res.push_back(tmp
        // % 10 + '0');
        succ = tmp / 10;
      }
      while (succ != 0) {
        res.push_back(succ % 10 + '0');
        succ /= 10;
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution solution;
  string n1 = "123", n2 = "0";
  auto result = solution.multiply(n1, n2);
  cout << result;
}