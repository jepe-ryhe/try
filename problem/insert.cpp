#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> res;
    intervals.push_back(newInterval);
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