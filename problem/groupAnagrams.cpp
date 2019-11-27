#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map(0);
        for (auto &&str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }
        vector<vector<string>> res;
        for (auto &&v : map)
        {
            res.push_back(v.second);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = solution.groupAnagrams(s);
    for (auto &&i : result)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}