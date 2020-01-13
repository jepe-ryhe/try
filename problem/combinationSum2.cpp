#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
  vector<int> candidates;
  vector<vector<int>> res;
  vector<int> path;

public:
  void DFS(int start, int target) {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    for (int i = start; i < candidates.size() && target - candidates[i] >= 0;
         i++) {
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      path.push_back(candidates[i]);

      DFS(i + 1, target - candidates[i]);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    DFS(0, target);
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> n = {2, 5, 2, 1, 2};
  auto result = solution.combinationSum2(n, 5);
  for (auto &&i : result) {
    for (auto &&j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}