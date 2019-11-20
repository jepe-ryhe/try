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
        root = new TreeNode<char>('A');
        root->left = new TreeNode<char>('B');
        root->left->left = new TreeNode<char>('C');
        root->right = new TreeNode<char>('D');
        root->right->left = new TreeNode<char>('E');
        root->right->right = new TreeNode<char>('F');
    }
    /*Tree(T* ds,int n){
        root = new TreeNode(ds[0]);
        int i;
        for(i = 1;i<n;i++){

        }
    }*/
    void levelorder()
    {
        queue<TreeNode<T> *> nodes;
        TreeNode<T> *p = root;
        if (p)
            nodes.push(p);
        while (!nodes.empty())
        {
            p = nodes.front();
            cout << p->data;
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
                cout << p->data;
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
                cout << p->data;
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
};
int main()
{
    Tree<char> tree;
    tree.levelorder();
    tree.preorder();
    tree.inorder();
    tree.postorder();
}
