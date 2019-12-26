#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int res = INT_MAX, l = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                res = min(res, i - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {2, 3, 1, 2, 4, 3};
    auto result = solution.minSubArrayLen(7, n);
    cout << result;
}