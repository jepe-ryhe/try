#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        unordered_set<int> myset(nums.begin(), nums.end());
        int res = 0;

        for (auto num : nums)
        {
            if (myset.count(num - 1) == 0)
            {
                int x = num + 1;
                while (myset.count(x))
                {
                    x++;
                }
                res = max(res, x - num);
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {100, 4, 200, 1, 3, 2};
    auto result = solution.longestConsecutive(n);
    cout << result;
}