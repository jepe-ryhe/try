#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void recoverTree(TreeNode *root) {
    if (NULL == root) {
      return;
    }
    TreeNode *node1 = NULL;
    TreeNode *node2 = NULL;

    TreeNode *mostRight = NULL;
    TreeNode *cur = root;

    TreeNode *pre = NULL;
    while (cur != NULL) {
      mostRight = cur->left;
      if (mostRight != NULL) {
        while (mostRight->right != NULL && mostRight->right != cur) {
          mostRight = mostRight->right;
        }
        if (mostRight->right == NULL) {
          mostRight->right = cur;
          cur = cur->left;
          continue;
        } else {
          mostRight->right = NULL;
        }
      }

      if (pre != NULL && pre->val > cur->val) {
        node1 = node1 == NULL ? pre : node1;
        node2 = cur;
      }

      pre = cur;
      cur = cur->right;
    }

    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
  }
};

int main() {
  Solution solution;
  TreeNode *t = new TreeNode(1);
  t->left = new TreeNode(3);
  t->left->right = new TreeNode(2);
  solution.recoverTree(t);
  cout << t->val << ' ' << t->left->val << ' ' << t->left->right->val;
}