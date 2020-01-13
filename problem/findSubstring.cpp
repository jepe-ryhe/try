#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res;
    if (words.size() < 1 || s.size() < 1 ||
        s.size() < words[0].size() * words.size())
      return res;
    int wordLen = words[0].size(), lens = wordLen * words.size(), target = 0,
        cur = 0;
    unordered_map<string, int> allWord;
    for (auto &it : words) {
      allWord[it]++;
      for (auto &i : it)
        target += i;
    }
    for (int i = 0; i < lens; i++)
      cur += s[i];

    for (int i = 0, j; i <= s.size() - lens;
         cur -= s[i], cur += s[lens + i++]) {

      if (cur != target)
        continue;

      unordered_map<string, int> tem(allWord);
      for (j = i; j < i + lens; j += wordLen)
        if (tem[s.substr(j, wordLen)]-- == 0)
          break;
      if (j == i + lens)
        res.push_back(i);
    }
    return res;
  }
};

int main() {
  Solution solution;
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};
  auto result = solution.findSubstring(s, words);
  for (auto &&i : result) {
    cout << i << ' ';
  }
}