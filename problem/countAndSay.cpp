#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string pre = countAndSay(n - 1);
        stringstream res;
        int count = 0;
        char p = pre[0];
        int l = pre.length();
        for (int i = 0; i < l; i++)
        {
            if (pre[i] == p)
            {
                count++;
            }
            else
            {
                res << count << p;
                p = pre[i];
                count = 1;
            }
        }
        res << count << p;
        return res.str();
    }
};

int main()
{
    Solution solution;
    auto result = solution.countAndSay(5);
    cout << result;
}