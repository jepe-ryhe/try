#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    const static int M = 1e9 + 7;

public:
    int knightDialer(int N)
    {
        if (N == 1)
            return 10;
        vector<long> n1(4, 1), n2(4, 0);
        for (int i = 1; i < N; i++)
        {
            n2[0] = (n1[3] * 2) % M;
            n2[1] = (n1[2] + n1[3]) % M;
            n2[2] = (n1[1] * 2) % M;
            n2[3] = (n1[1] * 2 + n1[0]) % M;
            swap(n1, n2);
        }
        long res = n1[1] * 4 + n1[0] + (n1[2] + n1[3]) * 2;
        return res % M;
    }
};

int main()
{
    Solution solution;
    auto result = solution.knightDialer(2);
    cout << result;
}