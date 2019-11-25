#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = nums.size();
        for (int i = 1; i < l; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
                i--;
                l--;
            }
        }
        return l;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 2};
    auto result = solution.removeDuplicates(nums);
    for (auto &&i : nums)
    {
        cout << i << ' ';
    }
}