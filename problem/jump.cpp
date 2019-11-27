#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int r = 0, p = 0, step = 0, l = nums.size();
        for (int i = 0; i < l - 1; i++)
        {
            p = max(p, nums[i] + i);
            if (i == r)
            {
                r = p;
                step++;
            }
        }
        return step;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {2, 3, 1, 1, 4};
    auto result = solution.jump(n);
    cout << result;
}