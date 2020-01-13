#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";
    return longestCommonPrefix(strs, 0, strs.size() - 1);
  }
  string longestCommonPrefix(vector<string> &strs, int left, int right) {
    if (left == right) {
      return strs[left];
    }
    // else if (right - left == 1)
    //{
    //    return compare(strs[left], strs[right]);
    //}
    else {
      int mid = (left + right) / 2;
      return compare(longestCommonPrefix(strs, left, mid),
                     longestCommonPrefix(strs, mid + 1, right));
    }
  }
  string compare(string s1, string s2) {
    int length = min(s1.length(), s2.length()), i = 0;
    for (; i < length; i++) {
      if (s1[i] != s2[i])
        break;
    }
    return s1.substr(0, i);
  }
};

int main() {
  Solution solution;
  vector<string> strs = {"caa", "", "a", "acb"};
  auto result = solution.longestCommonPrefix(strs);
  cout << result;
}