#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(const T &ele)
    {
        data = ele;
        left = 0;
        right = 0;
    }
};
template <class T>
class Tree
{
public:
    TreeNode<T> *root;
    Tree()
    {
        root = new TreeNode<int>(121);
        root->left = new TreeNode<int>(99);
        root->right = new TreeNode<int>(250);
        root->left->right = new TreeNode<int>(110);
        root->right->left = new TreeNode<int>(200);
        root->right->right = new TreeNode<int>(350);
        //root->left->right->left = new TreeNode<int>(105);
    }
    TreeNode<T> *search(TreeNode<T> *root, T key)
    {
        TreeNode<T> *curr = root;
        while (root && (key != curr->data))
        {
            curr = (key < curr->data) ? search(curr->left, key) : search(curr->right, key);
        }
        return curr;
    }
    void insert(T val)
    {
        TreeNode<T> *p = root, *prev = 0;
        while (p != 0)
        {
            prev = p;
            if (p->data < val)
                p = p->right;
            else
                p = p->left;
        }
        if (!root)
            root = new TreeNode<T>(val);
        else if (prev->data < val)
            prev->right = new TreeNode<T>(val);
        else
            prev->left = new TreeNode<T>(val);
    }
    void del(TreeNode<T> *node)
    {
        TreeNode<T> *p, *t;
        if (!node->right)
            node = node->left;
        else if (!node->left)
            node = node->right;
        else
        {
            t = node->left;
            p = node;
            while (t->right)
            {
                p = t;
                t = t->right;
            }
            node->data = t->data;
            if (p == node)
                p->left = t->left;
            else
                p->right = t->left;
        }
        delete t;
    }
    void levelorder()
    {
        queue<TreeNode<T> *> nodes;
        TreeNode<T> *p = root;
        if (p)
            nodes.push(p);
        while (!nodes.empty())
        {
            p = nodes.front();
            cout << p->data << ' ';
            nodes.pop();
            if (p->left)
                nodes.push(p->left);
            if (p->right)
                nodes.push(p->right);
        }
        cout << endl;
    }
    void preorder()
    {
        stack<TreeNode<T> *> nodes;
        TreeNode<T> *p = root;
        while (!nodes.empty() || p)
        {
            if (p)
            {
                cout << p->data << ' ';
                if (p->right)
                    nodes.push(p->right);
                p = p->left;
            }
            else
            {
                p = nodes.top();
                nodes.pop();
            }
        }
        cout << endl;
    }
    void inorder()
    {
        stack<TreeNode<T> *> nodes;
        TreeNode<T> *p = root;
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
                cout << p->data << ' ';
                p = p->right;
                nodes.pop();
            }
        }
        cout << endl;
    }
    void postorder()
    {
        stack<TreeNode<T> *> nodes;
        TreeNode<T> *p = root;
        TreeNode<T> *pre = root;
        while (p)
        {
            for (; p->left; p = p->left)
                nodes.push(p);
            while (p && (!p->right || p->right == pre))
            {
                cout << p->data;
                pre = p;
                if (nodes.empty())
                    return;
                p = nodes.top();
                nodes.pop();
            }
            nodes.push(p);
            p = p->right;
        }
        cout << endl;
    }
    int getDepth(TreeNode<T> *root)
    {
        int ldepth, rdepth;
        if (!root)
            return 0;
        else
        {
            rdepth = getDepth(root->right);
            ldepth = getDepth(root->left);
            return (rdepth > ldepth) ? (rdepth + 1) : (ldepth + 1);
        }
    }
};
int main()
{
    Tree<int> tree;
    tree.levelorder();
    tree.insert(105);
    tree.levelorder();
    tree.del(tree.search(tree.root, 250));
    tree.levelorder();
    tree.inorder();
    tree.preorder();
}
