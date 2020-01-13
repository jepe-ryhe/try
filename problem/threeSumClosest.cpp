#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3)
      return 0;
    int result = 0, g = INT_MAX;
    int length = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < length; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1;
      int r = length - 1;
      while (l < r) {
        int tmp = nums[i] + nums[l] + nums[r];
        if (abs(tmp - target) < g) {
          g = abs(tmp - target);
          result = tmp;
        }
        if (tmp > target) {
          r--;
        } else if (tmp < target) {
          l++;
        } else if (tmp == target) {
          return result;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums({1, 1, 1});
  int t = 3;
  auto result = solution.threeSumClosest(nums, t);
  cout << result;
}