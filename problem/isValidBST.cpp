#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isValid(TreeNode *current, long left, long right) {
    if (current == nullptr)
      return true;
    else if (current->val <= left || current->val >= right)
      return false;
    return isValid(current->left, left, current->val) &&
           isValid(current->right, current->val, right);
  }
  bool isValidBST(TreeNode *root) { return isValid(root, LONG_MIN, LONG_MAX); }
};

int main() {
  Solution solution;
  TreeNode *t = new TreeNode(2);
  t->left = new TreeNode(1);
  t->right = new TreeNode(3);
  auto result = solution.isValidBST(t);
  cout << result;
}