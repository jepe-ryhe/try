#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int len = graph.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(1 << len, vector<int>(len, len * len));
        for (int i = 0; i < len; i++)
        {
            q.push(make_pair(1 << i, i));
            dist[1 << i][i] = 0;
        }
        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            int d = dist[node.first][node.second];
            if (node.first == (1 << len) - 1)
                return d;

            for (auto &&child : graph[node.second])
            {
                int c = node.first | (1 << child);
                if (d + 1 < dist[c][child])
                {
                    dist[c][child] = d + 1;
                    q.push(make_pair(c, child));
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> g = {{1, 2, 3}, {0}, {0}, {0}};
    auto result = solution.shortestPathLength(g);
    cout << result;
}