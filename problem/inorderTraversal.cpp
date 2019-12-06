#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> nodes;
        TreeNode *p = root;
        vector<int> res;
        while (!nodes.empty() || p)
        {
            if (p)
            {
                nodes.push(p);
                p = p->left;
            }
            else
            {
                p = nodes.top();
                res.push_back(p->val);
                p = p->right;
                nodes.pop();
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    TreeNode *t = new TreeNode(1);
    t->right = new TreeNode(2);
    t->right->left = new TreeNode(3);
    auto result = solution.inorderTraversal(t);
    for (auto &&i : result)
    {
        cout << i << ' ';
    }
}