#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[l] == target)
                return l;
            if (nums[r] == target)
                return r;
            if (nums[m] == target)
                return m;
            if ((nums[l] < target && target < nums[m]) || (target < nums[m] && nums[m] < nums[l]) || (nums[m] < nums[l] && nums[l] < target))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l == r && nums[l] == target ? l : -1;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {4, 5, 6, 7, 0, 1, 2};
    auto result = solution.search(n, 0);
    cout << result;
}