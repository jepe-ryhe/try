#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[l])
            {
                l++;
                continue;
            }
            if (nums[mid] > nums[l])
            {
                if (nums[mid] > target && nums[l] <= target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[r] >= target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        if (l == r && nums[l] == target)
            return true;
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {1, 3};
    auto result = solution.search(n, 3);
    cout << result;
}