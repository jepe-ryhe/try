#include <iostream>
using namespace std;

class Solution
{
public:
    double basicPow(double x, long n)
    {
        if (n == 0)
            return 1.0;
        double half = basicPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
    double myPow(double x, int n)
    {
        long N = n;
        if (N == 0)
            return 1.0;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return basicPow(x, N);
    }
};

int main()
{
    Solution solution;
    auto result = solution.myPow(2, 10);
    cout << result;
}