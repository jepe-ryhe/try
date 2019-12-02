#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p0 = 0, curr = 0;
        int p2 = nums.size() - 1;

        while (curr <= p2)
        {
            if (nums[curr] == 0)
            {
                swap(nums[curr++], nums[p0++]);
            }
            else if (nums[curr] == 2)
            {
                swap(nums[curr], nums[p2--]);
            }
            else
                curr++;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> n = {2, 0, 2, 1, 1, 0};
    solution.sortColors(n);
    for_each(n.begin(), n.end(), [](int i) { cout << i << ' '; });
}