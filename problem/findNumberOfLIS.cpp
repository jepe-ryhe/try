#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<pair<int, int>> dp(len, {1, 1});
        int m = 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i].first < dp[j].first + 1)
                    {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                    else if (dp[i].first == dp[j].first + 1)
                    {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            m = max(m, dp[i].first);
        }
        int res = 0;
        for (auto [length, num] : dp)
        {
            if (length == m)
            {
                res += num;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> v = {1, 3, 5, 4, 7};
    auto result = solution.findNumberOfLIS(v);
    cout << result;
}