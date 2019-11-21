#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int r = 0;
        while (x > r)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return x == r || x == r / 10;
    }
};

int main()
{
    Solution solution;
    int x = 12322;
    auto result = solution.isPalindrome(x);
    cout << result;
}