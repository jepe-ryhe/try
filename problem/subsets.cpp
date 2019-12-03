#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int S = nums.size();
        int N = 1 << S;
        vector<vector<int>> res;
        for (int i = 0; i < N; ++i)
        {
            vector<int> v;
            for (int j = 0; j < S; ++j)
                if (i & (1 << j))
                    v.push_back(nums[j]);
            res.push_back(v);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {1, 2, 3};
    auto result = solution.subsets(n);
    for (auto &&i : result)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}