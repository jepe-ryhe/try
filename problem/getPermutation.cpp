#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    string num;
    for (int i = 1; i <= n; i++) {
      num.push_back(i + '0');
    }
    for (int i = 1; i < k; i++) {
      next_permutation(num.begin(), num.end());
    }
    return num;
  }
};

int main() {
  Solution solution;
  auto result = solution.getPermutation(3, 3);
  cout << result;
}