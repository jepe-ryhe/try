#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(target - nums[i])) {
        return {map[target - nums[i]], i};
      } else {
        map[nums[i]] = i;
      }
    }
    return {0, 0};
  }
};

int main() {
  Solution solution;
  vector<int> num({2, 7, 11, 15});
  auto s = solution.twoSum(num, 9);
  for (auto &&i : s) {
    cout << i << ' ';
  }
}