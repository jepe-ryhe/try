#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    const vector<pair<int, string>> v{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    string intToRoman(int num)
    {
        string res;
        for (int i = 0; i < v.size() && num > 0; ++i)
        {
            int k = num / v[i].first;
            num %= v[i].first;
            for (int j = 0; j < k; ++j)
            {
                res += v[i].second;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int num = 123;
    auto result = solution.intToRoman(num);
    cout << result;
}