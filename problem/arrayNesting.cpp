#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> f, s;
  int find(int n) {
    if (f[n] != n) {
      f[n] = find(f[n]);
    }
    return f[n];
  }
  void uni(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
      f[fx] = fy;
      s[fy] += s[fx];
      s[fx] = 0;
    }
  }

public:
  int arrayNesting(vector<int> &nums) {
    int len = nums.size();
    f = vector<int>(len, 0);
    s = vector<int>(len, 1);
    for (int i = 0; i < len; i++) {
      f[i] = i;
    }
    for (int i = 0; i < len; i++) {
      uni(i, nums[i]);
    }
    return *max_element(s.begin(), s.end());
  }
};

int main() {
  Solution solution;
  vector<int> n = {5, 4, 0, 3, 1, 6, 2};
  auto result = solution.arrayNesting(n);
  cout << result;
}