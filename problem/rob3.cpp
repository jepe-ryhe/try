#include <iostream>
#include <utility>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  pair<int, int> dfs(TreeNode *root) {
    if (root == nullptr) {
      return {0, 0};
    }
    auto [lu, ln] = dfs(root->left);
    auto [ru, rn] = dfs(root->right);
    return {root->val + ln + rn, max(lu, ln) + max(ru, rn)};
  }

public:
  int rob(TreeNode *root) {
    auto [rootu, rootn] = dfs(root);
    return max(rootu, rootn);
  }
};

int main() {
  Solution solution;
  TreeNode *r = new TreeNode(3);
  r->left = new TreeNode(2);
  r->left->right = new TreeNode(3);
  r->right = new TreeNode(3);
  r->right->right = new TreeNode(1);
  auto result = solution.rob(r);
  cout << result;
}