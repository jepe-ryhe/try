#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool btreeGameWinningMove(TreeNode *root, int n, int x) {
    int redl = 0, redr = 0;
    function<int(TreeNode *)> dfs = [&](TreeNode *root) {
      if (root == NULL) {
        return 0;
      }
      int left = dfs(root->left);
      int right = dfs(root->right);
      if (root->val == x) {
        redl = left;
        redr = right;
      }
      return left + right + 1;
    };
    dfs(root);
    int parent = n - redl - redr - 1;
    auto all = {redl, redr, parent};
    return any_of(all.begin(), all.end(), [=](int i) { return i > n / 2; });
  }
};

int main() {
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  auto result = solution.btreeGameWinningMove(root, 3, 3);
  cout << result;
}