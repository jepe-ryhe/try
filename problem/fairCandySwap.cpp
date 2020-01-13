#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
    auto ra = accumulate(A.begin(), A.end(), 0);
    auto rb = accumulate(B.begin(), B.end(), 0);
    auto diff = (ra - rb) / 2;
    for (auto &&i : A) {
      if (find(B.begin(), B.end(), i - diff) != B.end()) {
        return {i, i - diff};
      }
    }
    return {};
  }
};

int main() {
  Solution solution;
  vector<int> a = {1, 1}, b = {2, 2};
  auto result = solution.fairCandySwap(a, b);
  for_each(result.begin(), result.end(), [](int i) { cout << i << ' '; });
}
