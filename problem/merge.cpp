#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    if (intervals.size() == 0)
      return {};
    sort(intervals.begin(), intervals.end());
    int len = intervals.size(), i = 0;
    while (i < len) {
      int l = intervals[i][0], r = intervals[i][1];
      while (i < len - 1 && r >= intervals[i + 1][0]) {
        i++;
        r = max(r, intervals[i][1]);
      }
      res.push_back({l, r});
      i++;
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> n = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  auto result = solution.merge(n);
  for (auto &&i : result) {
    for (auto &&j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}