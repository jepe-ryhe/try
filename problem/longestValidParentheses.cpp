#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int l = s.length();
        int ll = 0, lr = 0, rl = 0, rr = 0;
        int res = 0;
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '(')
            {
                ll++;
            }
            else
            {
                lr++;
            }
            if (ll == lr)
            {
                res = max(res, lr * 2);
            }
            else if (lr >= ll)
            {
                ll = lr = 0;
            }

            if (s[l - i - 1] == '(')
            {
                rl++;
            }
            else
            {
                rr++;
            }
            if (rl == rr)
            {
                res = max(res, rl * 2);
            }
            else if (rl >= rr)
            {
                rr = rl = 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string s = ")(";
    auto result = solution.longestValidParentheses(s);
    cout << result;
}