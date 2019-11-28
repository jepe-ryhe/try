#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int p = 0, l = nums.size();
        for (int i = 0; i < l; i++)
        {
            if (i > p)
                return false;
            p = max(p, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {2, 3, 1, 1, 4};
    auto result = solution.canJump(n);
    cout << result;
}