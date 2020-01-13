#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    stringstream ss(path);
    vector<string> strs;
    string res = "", tmp = "";
    while (getline(ss, tmp, '/')) {
      if (tmp == "" || tmp == ".")
        continue;
      else if (tmp == ".." && !strs.empty())
        strs.pop_back();
      else if (tmp != "..")
        strs.push_back(tmp);
    }
    for (auto &&s : strs) {
      res += "/" + s;
    }
    if (res == "")
      return "/";
    return res;
  }
};

int main() {
  Solution solution;
  string s = "/a/./b/../../c/";
  auto result = solution.simplifyPath(s);
  cout << result;
}