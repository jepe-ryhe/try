#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        //next_permutation(nums.begin(),nums.end());
        if (nums.size() == 0 || nums.size() == 1)
            return;
        int l = nums.size();
        int i = l - 1;
        for (;;)
        {
            int ii = i;
            i--;
            if (nums[i] < nums[ii])
            {
                int j = l - 1;
                while (nums[i] >= nums[j])
                    j--;
                iter_swap(nums.begin() + i, nums.begin() + j);
                reverse(nums.begin() + ii, nums.end());
                return;
            }
            if (i == 0)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> n = {1, 1};
    solution.nextPermutation(n);
    for (auto &&i : n)
    {
        cout << i << ' ';
    }
}