#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    this->map = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                 {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    if (digits.length() == 0)
      return {};
    this->mLevel = digits.length();
    this->digits = digits;
    dfs("", 0);
    return this->result;
  }

private:
  void dfs(string res, int l) {
    if (l == this->mLevel) {
      result.push_back(res);
    }
    char n = this->digits[l];
    string s = map[n];
    for (auto &&i : s) {
      dfs(res + i, l + 1);
    }
  }
  string digits;
  int mLevel;
  vector<string> result;
  unordered_map<char, string> map;
};

int main() {
  Solution solution;
  string s = "23";
  auto result = solution.letterCombinations(s);
  for (auto &&i : result) {
    cout << i << endl;
  }
}