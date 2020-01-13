#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<string>> res;
  vector<string> sol;
  vector<bool> col, ll, rr;
  int num;
  void solve(int n) {
    if (n == num) {
      res.push_back(sol);
      return;
    }
    for (int i = 0; i < num; i++) {
      int l = n + i;
      int r = n - i + num - 1;
      if (col[i] && ll[l] && rr[r]) {
        sol[n][i] = 'Q';
        col[i] = false;
        ll[l] = false;
        rr[r] = false;

        solve(n + 1);

        sol[n][i] = '.';
        col[i] = true;
        ll[l] = true;
        rr[r] = true;
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    if (n == 1)
      return {{"Q"}};
    if (n == 2 || n == 3)
      return {};
    num = n;
    sol = vector<string>(n, string(n, '.'));
    col = vector<bool>(n, true);
    ll = vector<bool>(2 * n - 2, true);
    rr = vector<bool>(2 * n - 2, true);
    solve(0);
    return this->res;
  }
};

int main() {
  Solution solution;
  auto result = solution.solveNQueens(1);
  for (auto &&i : result) {
    for (auto &&j : i) {
      cout << j << endl;
    }
    cout << endl;
  }
}