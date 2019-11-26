#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<int>> l(9), r(9), b(9);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (l[i].find(board[i][j]) != l[i].end())
                    return false;
                if (r[j].find(board[i][j]) != r[j].end())
                    return false;
                int box = i / 3 * 3 + j / 3;
                if (b[box].find(board[i][j]) != b[box].end())
                    return false;
                l[i].insert(board[i][j]);
                r[j].insert(board[i][j]);
                b[box].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> b({{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}});
    auto result = solution.isValidSudoku(b);
    cout << result;
}