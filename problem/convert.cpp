#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1) return s;
        int l = s.length(), step = 2 * numRows - 2;
        string result;
        for (int r = 0; r < numRows; r++)
        {
            for (int i = r; i < l; i += step)
            {
                result.push_back(s[i]);
                if (r != 0 && r != numRows - 1 && i + step - 2 * r < l)
                {
                    result.push_back(s[i + step - 2 * r]);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "LEETCODEISHIRING";
    auto result = solution.convert(s, 4);
    cout << result;
}