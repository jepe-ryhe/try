#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return vector<vector<int>>();
    vector<vector<int>> result;
    int length = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < length; i++) {
      if (nums[i] > 0)
        return result;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1;
      int r = length - 1;
      while (l < r) {
        int tmp = nums[i] + nums[l] + nums[r];
        if (tmp > 0) {
          r--;
        } else if (tmp < 0) {
          l++;
        } else if (tmp == 0) {
          result.push_back(vector<int>({nums[i], nums[l], nums[r]}));
          while (l < r && nums[r] == nums[r - 1]) {
            r--;
          }
          while (l < r && nums[l] == nums[l + 1]) {
            l++;
          }
          r--;
          l++;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums({-1, 0, 1, 2, -1, -4});
  auto result = solution.threeSum(nums);
  for (auto &&i : result) {
    for (auto &&j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}