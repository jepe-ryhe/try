#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  TreeNode *copyTree(TreeNode *root, int delta = 0) {
    auto nroot = new TreeNode(root->val + delta);
    queue<TreeNode *> qt;
    queue<TreeNode *> qo;
    qo.push(root);
    qt.push(nroot);
    while (!qt.empty()) {
      auto o_root = qo.front();
      qo.pop();
      auto t_root = qt.front();
      qt.pop();
      if (o_root->left) {
        t_root->left = new TreeNode(o_root->left->val + delta);
        qo.push(o_root->left);
        qt.push(t_root->left);
      }
      if (o_root->right) {
        t_root->right = new TreeNode(o_root->right->val + delta);
        qo.push(o_root->right);
        qt.push(t_root->right);
      }
    }
    return nroot;
  }

public:
  vector<TreeNode *> generateTrees(int n) {
    static vector<vector<TreeNode *>> dp(1, vector<TreeNode *>(1, NULL));
    int c_size = n + 1;
    int o_size = dp.size();
    if (c_size > dp.size())
      dp.resize(c_size);

    for (int i = o_size; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        const auto &left = dp[j - 1];
        const auto &right = dp[i - j];
        auto &cc = dp[i];
        for (const auto left_ptr : left)
          for (const auto right_ptr : right) {
            auto root = new TreeNode(j);
            if (j > 1)
              root->left = copyTree(left_ptr);
            if (i > j)
              root->right = copyTree(right_ptr, j);
            cc.push_back(root);
          }
      }
    }
    if (n == 0)
      return {};
    return dp[n];
  }
};