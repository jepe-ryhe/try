#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int ls = s.length(), lt = t.length();
        vector<int> c(256, 0);
        for (auto &&i : t)
        {
            c[i]++;
        }
        int len = 0, min = s.length();
        string res;
        for (int l = 0, r = 0; r < ls; r++)
        {
            c[s[r]]--;
            if (c[s[r]] >= 0)
                len++;
            while (len == lt)
            {
                if (r - l + 1 <= min)
                {
                    min = r - l + 1;
                    res = s.substr(l, min);
                }
                c[s[l]]++;
                if (c[s[l]] > 0)
                    len--;
                l++;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    auto result = solution.minWindow(s, t);
    cout << result;
}