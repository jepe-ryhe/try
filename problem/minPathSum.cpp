#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return {};
        int n = grid[0].size();
        if (n == 0)
            return {};
        vector<vector<int>> map(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    map[i][j] = grid[i][j];
                    continue;
                }
                map[i][j] = min((i > 0 ? map[i - 1][j] : INT_MAX), (j > 0 ? map[i][j - 1] : INT_MAX)) + grid[i][j];
            }
        }

        return map[m - 1][n - 1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> g = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    auto result = solution.minPathSum(g);
    cout << result;
}