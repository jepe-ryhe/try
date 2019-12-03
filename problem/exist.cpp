#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int length)
    {
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || length >= word.size() || word[length] != board[i][j])
        {
            return false;
        }
        if (length == word.size() - 1 && word[length] == board[i][j])
        {
            return true;
        }
        char tmp = board[i][j];
        board[i][j] = '0';
        bool res = dfs(board, word, i, j + 1, length + 1) || dfs(board, word, i, j - 1, length + 1) || dfs(board, word, i + 1, j, length + 1) || dfs(board, word, i - 1, j, length + 1);
        board[i][j] = tmp;
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> b = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    auto result = solution.exist(b, "ABCCED");
    cout << result;
}