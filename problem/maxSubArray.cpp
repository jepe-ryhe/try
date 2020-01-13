#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int result = INT_MIN;
    int l = int(nums.size());
    vector<int> dp(l);
    dp[0] = nums[0];
    result = dp[0];
    for (int i = 1; i < l; i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      result = max(result, dp[i]);
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> n = {1, -1, -1};
  auto result = solution.maxSubArray(n);
  cout << result;
}