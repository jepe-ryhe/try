#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> map, size;
    int find(int x)
    {
        if (x != map[x])
            map[x] = find(map[x]);
        return map[x];
    }
    void uni(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            if (size[fx] < size[fy])
            {
                map[fx] = fy;
                size[fy] += size[fx];
            }
            else
            {
                map[fy] = fx;
                size[fx] += size[fy];
            }
        }
    }

public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size(), m = n / 2, res = 0, cir = 0;
        map = vector<int>(m, 0);
        size = vector<int>(m, 1);
        for (int i = 0; i < m; i++)
        {
            map[i] = i;
        }
        for (int i = 0; i < n; i += 2)
        {
            uni(row[i] / 2, row[i + 1] / 2);
        }
        for (int i = 0; i < m; i++)
        {
            if (i == find(i))
            {
                cir++;
            }
        }
        return m - cir;
    }
};

int main()
{
    Solution solution;
    vector<int> n = {0, 2, 1, 3};
    auto result = solution.minSwapsCouples(n);
    cout << result;
}