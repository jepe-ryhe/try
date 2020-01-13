#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> res;
    int c = pow(2, n);
    for (int i = 0; i < c; i++) {
      res.push_back((i >> 1) ^ i);
    }
    return res;
  }
};

int main() {
  Solution solution;
  auto result = solution.grayCode(2);
  for (auto &&i : result) {
    cout << i << ' ';
  }
}