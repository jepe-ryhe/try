#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target,
                                     int p) {
    if (candidates.size() == 0)
      return {{}};
    vector<vector<int>> res = {};
    int l = candidates.size();
    for (int i = p; i < l; i++) {
      if (candidates[i] == target) {
        res.push_back({candidates[i]});
      } else if (candidates[i] < target) {
        auto pre = combinationSum(candidates, target - candidates[i], i);
        for (auto &&r : pre) {
          r.push_back(candidates[i]);
          res.push_back(r);
        }
      }
    }
    return res;
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    if (candidates.size() == 0)
      return {{}};
    vector<vector<int>> res = {};
    int l = candidates.size();
    for (int i = 0; i < l; i++) {
      if (candidates[i] == target) {
        res.push_back({candidates[i]});
      } else if (candidates[i] < target) {
        auto pre = combinationSum(candidates, target - candidates[i], i);
        for (auto &&r : pre) {
          r.push_back(candidates[i]);
          res.push_back(r);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> n = {2, 3, 6, 7};
  auto result = solution.combinationSum(n, 7);
  for (auto &&i : result) {
    for (auto &&j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}