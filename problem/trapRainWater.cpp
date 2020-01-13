#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  struct node {
    int x, y, h;
    node(int x, int y, int h) : x(x), y(y), h(h){};
    bool operator<(node n) const { return h > n.h; }
  };
  const vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

public:
  // int trapRainWater(vector<vector<int>> &heightMap)
  //{
  //    priority_queue<node> q;
  //    if (heightMap.size() < 3 || heightMap[0].size() < 3)
  //        return 0;
  //    int row = heightMap.size(), col = heightMap[0].size();
  //    vector<vector<int>> dp(row, vector<int>(col, 0));
  //    for (int i = 0; i < row; i++)
  //    {
  //        q.push({i, 0, heightMap[i][0]});
  //        dp[i][0] = 1;
  //        q.push({i, col - 1, heightMap[i][col - 1]});
  //        dp[i][col - 1] = 1;
  //    }
  //    for (int i = 1; i < col - 1; i++)
  //    {
  //        q.push({0, i, heightMap[0][i]});
  //        dp[0][i] = 1;
  //        q.push({row - 1, i, heightMap[row - 1][i]});
  //        dp[row - 1][i] = 1;
  //    }
  //    int res = 0;
  //    while (!q.empty())
  //    {
  //        auto [x, y, h] = q.top();
  //        for (auto [ix, iy] : dir)
  //        {
  //            int dx = x + ix, dy = y + iy;
  //            if (dx < 0 || dx >= row || dy < 0 || dy >= col || dp[dx][dy] ==
  //            1)
  //            {
  //                continue;
  //            }
  //            if (h > heightMap[dx][dy])
  //            {
  //                res += h - heightMap[dx][dy];
  //                heightMap[dx][dy] = h;
  //            }
  //            q.push({dx, dy, heightMap[dx][dy]});
  //            dp[dx][dy] = 1;
  //        }
  //        q.pop();
  //    }
  //    return res;
  //}

  int trapRainWater(vector<vector<int>> &heightMap) {
    const int M = heightMap.size();
    if (M < 3)
      return 0;
    const int N = heightMap[0].size();
    if (N < 3)
      return 0;
    vector<vector<int>> water_level(1, vector<int>(N, 0));
    water_level.push_back(vector<int>(N, INT_MAX));
    water_level[1][0] = 0;
    water_level[1][N - 1] = 0;
    for (int i = 2; i < M - 1; ++i)
      water_level.push_back(water_level[1]);
    water_level.push_back(water_level[0]);
    bool flowing = true;
    while (flowing) {
      flowing = false;
      for (int i = 1; i < M - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
          const int height =
              min(max(water_level[i - 1][j], heightMap[i - 1][j]),
                  max(water_level[i][j - 1], heightMap[i][j - 1]));
          if (water_level[i][j] > height) {
            if (!flowing)
              flowing = true;
            water_level[i][j] = height;
          }
        }
      }

      for_each(water_level.begin(), water_level.end(), [](vector<int> v) {
        for_each(v.begin(), v.end(), [](int i) { cout << i << ' '; });
        cout << endl;
      });
      cout << endl;

      if (!flowing)
        break;
      flowing = false;
      for (int i = M - 2; i > 0; --i) {
        for (int j = N - 2; j > 0; --j) {
          const int height =
              min(max(water_level[i + 1][j], heightMap[i + 1][j]),
                  max(water_level[i][j + 1], heightMap[i][j + 1]));
          if (water_level[i][j] > height) {
            if (!flowing)
              flowing = true;
            water_level[i][j] = height;
          }
        }
      }

      for_each(water_level.begin(), water_level.end(), [](vector<int> v) {
        for_each(v.begin(), v.end(), [](int i) { cout << i << ' '; });
        cout << endl;
      });
      cout << endl;
    }
    int volumn = 0;
    for (int i = 1; i < M - 1; ++i) {
      for (int j = 1; j < N - 1; ++j) {
        if (water_level[i][j] <= heightMap[i][j])
          continue;
        volumn += water_level[i][j] - heightMap[i][j];
      }
    }
    return volumn;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> h = {
      {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
  auto result = solution.trapRainWater(h);
  cout << result;
}