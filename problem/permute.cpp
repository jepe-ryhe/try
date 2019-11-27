#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int i)
    {
        if (i == nums.size())
            res.push_back(nums);
        for (int j = i; j < nums.size(); j++)
        {
            if(nums[i] == nums[j]) continue;
            swap(nums[i], nums[j]);
            backtrack(nums, res, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};

int main()
{
    Solution solution;
    vector<int> n = {1, 1, 3};
    auto result = solution.permute(n);
    for (auto &&i : result)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}