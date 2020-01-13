#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestRepunitDivByK(int K) {
    if (K % 2 == 0 || K % 5 == 0)
      return -1;
    vector<bool> v(K, false);
    int n = 0, res = 0;
    while (!v[n]) {
      v[n] = true;
      n = (10 * n + 1) % K;
      res++;
    }
    return n == 0 ? res : -1;
  }
};

int main() {
  Solution solution;
  auto result = solution.smallestRepunitDivByK(5);
  cout << result;
}