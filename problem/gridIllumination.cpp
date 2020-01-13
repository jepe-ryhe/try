#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  const vector<pair<int, int>> dist = {{0, 0},  {0, 1},  {0, -1},
                                       {1, 0},  {1, 1},  {1, -1},
                                       {-1, 0}, {-1, 1}, {-1, -1}};

public:
  vector<int> gridIllumination(int N, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {
    unordered_map<int, int> row, col, dil, dir;
    unordered_set<long long> p;
    for (auto &&l : lamps) {
      row[l[0]]++;
      col[l[1]]++;
      dil[l[0] + l[1]]++;
      dir[l[0] - l[1]]++;
      p.insert(l[0] * N + l[1]);
    }
    vector<int> res;
    for (auto &&q : queries) {
      int r = q[0];
      int c = q[1];
      int state = 0;

      if (row.count(r) && row[r])
        state = 1;

      if (!state && col.count(c) && col[c])
        state = 1;

      if (!state && dil.count(r + c) && dil[r + c])
        state = 1;

      if (!state && dir.count(r - c) && dir[r - c])
        state = 1;

      res.push_back(state);

      for (auto &&[lx, rx] : dist) {
        int ln = lx + q[0];
        int rn = rx + q[1];
        if (ln >= 0 && ln < N && rn >= 0 && rn < N) {
          long long k = ln * N + rn;
          if (p.count(k)) {
            p.erase(k);
            row[ln]--;
            col[rn]--;
            dil[ln + rn]--;
            dir[ln - rn]--;
          }
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> l = {{0, 0}, {4, 4}};
  vector<vector<int>> q = {{1, 1}, {1, 0}};
  auto result = solution.gridIllumination(5, l, q);
  for (auto &&i : result) {
    cout << i << ' ';
  }
}