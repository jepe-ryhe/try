#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    bool res;
    unordered_map<string, unordered_set<char>> map;
    void dfs(string bottom, string next, int index)
    {
        if (res == true)
            return;
        if (bottom.length() == 1)
        {
            res = true;
            return;
        }
        if (index == bottom.length() - 1)
        {
            dfs(next, "", 0);
        }
        else
        {
            string s = bottom.substr(index, 2);
            for (auto &&c : map[s])
            {
                dfs(bottom, next + c, index + 1);
            }
        }
    }

public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        res = false;
        for (auto &&str : allowed)
        {
            map[str.substr(0, 2)].insert(str[2]);
        }
        dfs(bottom, "", 0);
        return res;
    }
};

int main()
{
    Solution solution;
    string b = "BCD";
    vector<string> all = {"BCG", "CDE", "GEA", "FFF"};
    auto result = solution.pyramidTransition(b, all);
    cout << (result == true ? "true" : "false");
}