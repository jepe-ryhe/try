#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        int l = 0, r = m * n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (matrix[mid / n][mid % n] == target)
            {
                return true;
            }
            if (matrix[mid / n][mid % n] < target)
            {
                l = mid + 1;
            }
            else if (matrix[mid / n][mid % n] > target)
            {
                r = mid;
            }
        }
        if (l == r && matrix[l / n][l % n] == target)
            return true;
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> m = {{1}};
    auto result = solution.searchMatrix(m, 1);
    cout << result;
}