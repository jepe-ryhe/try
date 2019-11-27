#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sl = s.length(), pl = p.length();
        int start = -1, m = 0;
        int i = 0, j = 0;
        while (i < sl)
        {
            if (j < pl && (s.at(i) == p.at(j) || p.at(j) == '?'))
            {
                i++;
                j++;
            }
            else if (j < pl && p.at(j) == '*')
            {
                start = j;
                m = i;
                j++;
            }
            else if (start != -1)
            {
                j = start + 1;
                m++;
                i = m;
            }
            else
            {
                return false;
            }
        }
        while (j < pl)
        {
            if (p.at(j) != '*')
                return false;
            j++;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "aa", p = "*";
    auto result = solution.isMatch(s, p);
    cout << (result ? "true" : "false");
}