#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int l = matrix.size();
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l - i; j++) {
        swap(matrix[j][i], matrix[l - i - 1][l - j - 1]);
      }
    }
    for (int i = 0; i < l / 2; i++) {
      swap(matrix[i], matrix[l - i - 1]);
    }
  }
};

int main() {
  Solution solution;
  vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  solution.rotate(m);
  for (auto &&i : m) {
    for (auto &&j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}