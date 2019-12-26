#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int P)
    {
        if (tokens.size() == 0)
            return 0;
        sort(tokens.begin(), tokens.end());
        if (P < tokens[0])
            return 0;
        int len = tokens.size(), l = 0, r = len - 1;
        int s = 0, res = 0;
        while (l <= r)
        {
            if (P < tokens[l])
            {
                if (s <= 0)
                    return res;
                P += tokens[r];
                s--;
                r--;
            }
            else
            {
                P -= tokens[l];
                s++;
                l++;
                res = max(s, res);
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> t = {100, 200, 300, 400};
    auto result = solution.bagOfTokensScore(t, 200);
    cout << result;
}