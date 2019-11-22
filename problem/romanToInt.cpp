#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> map = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int l = s.length(), result(0);
        for (int i = 0; i < l; i++)
        {
            if (map[s[i]] < map[s[i + 1]])
            {
                result -= map[s[i]];
            }
            else
            {
                result += map[s[i]];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "MCMXCIV";
    auto result = solution.romanToInt(s);
    cout << result;
}