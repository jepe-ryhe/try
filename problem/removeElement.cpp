#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[l - 1];
                l--;
                i--;
            }
        }
        return l;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    auto result = solution.removeElement(nums, 2);
    for (int i = 0; i < result; i++)
    {
        cout << nums[i] << ' ';
    }
}