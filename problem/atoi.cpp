#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int result = 0;
    stringstream ss;
    ss << str;
    ss >> result;
    return result;
  }
  // int myAtoi(string str)
  //{
  //    int res = 0;
  //    int i = 0;
  //    int flag = 1;
  //    while (str[i] == ' ')
  //    {
  //        i++;
  //    }
  //    if (str[i] == '-')
  //    {
  //        flag = -1;
  //    }
  //    if (str[i] == '+' || str[i] == '-')
  //    {
  //        i++;
  //    }
  //    while (i < str.size() && isdigit(str[i]))
  //    {
  //        int r = str[i] - '0';
  //        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
  //        {
  //            return flag > 0 ? INT_MAX : INT_MIN;
  //        }
  //        res = res * 10 + r;
  //        i++;
  //    }
  //    return res * flag;
  //}
};

int main() {
  Solution solution;
  string s = "4193 with words";
  auto result = solution.myAtoi(s);
  cout << result;
}