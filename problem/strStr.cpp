#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.length() == 0)
            return 0;
        int i, j = 0;
        vector<int> n = next(needle);
        for (i = 0; i < haystack.length(); i++)
        {
            while (needle[j] != haystack[i] && j > 0)
                j = n[j - 1];
            if (needle[j] == haystack[i])
                j++;
            if (j == needle.length())
                return i - j + 1;
        }
        return -1;
    }

private:
    vector<int> next(string p)
    {
        int l = p.length();
        if (l < 0)
            return {};
        vector<int> res(l);
        res[0] = 0;
        for (int i = 1; i < l; i++)
        {
            int k = res[i - 1];
            while (k > 0 && p[i] != p[k])
                k = res[k - 1];
            if (p[i] == p[k])
                res[i] = k + 1;
            else
                res[i] = 0;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string t = "aaaaa", p = "";
    auto result = solution.strStr(t, p);
    cout << result;
}