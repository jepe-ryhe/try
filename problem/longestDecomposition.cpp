#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int longestDecomposition(string text)
    {
        int res = 0;
        int prev = 0;
        int S = text.size();
        for (int i = 0; i < S / 2; ++i)
        {
            if ((text.substr(prev, i - prev + 1)) == text.substr(S - 1 - i, i - prev + 1))
            {
                res += 2;
                prev = i + 1;
            }
        }
        if (S % 2 == 1 || prev < S / 2)
            ++res;
        return res;
    }
};

int main()
{
    Solution solution;
    string s = "ghiabcdefhelloadamhelloabcdefghi";
    auto result = solution.longestDecomposition(s);
    cout << result;
}