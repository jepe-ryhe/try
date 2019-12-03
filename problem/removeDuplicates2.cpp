#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = nums.size();
        if (l < 2)
            return l;
        int pl = 1;
        for (int pr = 2; pr < l; pr++)
        {
            if (nums[pl - 1] != nums[pr])
            {
                nums[++pl] = nums[pr];
            }
        }
        return pl + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {};
    auto result = solution.removeDuplicates(n);
    for (int i = 0; i < result; i++)
    {
        cout << n[i] << ' ';
    }
}