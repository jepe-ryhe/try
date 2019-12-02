#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> map(l1 + 1, (vector<int>(l2 + 1, 0)));
        for (int i = 0; i < l2; i++)
        {
            map[0][i + 1] = map[0][i] + 1;
        }
        for (int i = 0; i < l1; i++)
        {
            map[i + 1][0] = map[i][0] + 1;
        }
        for (int i = 1; i < l1 + 1; i++)
        {
            for (int j = 1; j < l2 + 1; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    map[i][j] = map[i - 1][j - 1];
                else
                    map[i][j] = min(min(map[i - 1][j - 1], map[i][j - 1]), map[i - 1][j]) + 1;
            }
        }
        return map[l1][l2];
    }
};

int main()
{
    Solution solution;
    string s1 = "intention", s2 = "execution";
    auto result = solution.minDistance(s1, s2);
    cout << result;
}