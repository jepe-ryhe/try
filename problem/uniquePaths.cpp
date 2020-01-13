#include <iostream>
using namespace std;

static int map[101][101] = {0};
class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0)
      return 0;
    if (m == 1 || n == 1)
      return 1;
    if (map[m][n] > 0)
      return map[m][n];
    map[m][n] = uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
    return map[m][n];
  }
};

int main() {
  Solution solution;
  auto result = solution.uniquePaths(3, 4);
  cout << result;
}