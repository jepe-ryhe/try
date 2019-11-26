#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int ll = 0, lr = nums.size() - 1, rl = 0, rr = nums.size() - 1;
        while (ll < lr && rl < rr)
        {
            int lm = (ll + lr / 2), rm = (rl + rr) / 2;
            if (target <= nums[lm])
            {
                lr = lm;
            }
            else
            {
                ll = lm + 1;
            }
            if (target < nums[rm])
            {
                rr = rm;
            }
            else
            {
                rl = rm + 1;
            }
        }
        if (nums[ll] == target && nums[rl - 1] == target)
        {
            return {ll, rl - 1};
        }
        else
        {
            return {-1, -1};
        }
    }
};

int main()
{
    Solution solution;
    vector<int> n = {1};
    auto result = solution.searchRange(n, 1);
    cout << result[0] << ' ' << result[1];
}