#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp
{
    bool operator()(ListNode *left, ListNode *right)
    {
        return left->val > right->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }
        if (size == 1) {
            return lists[0];
        }
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (auto &&i : lists)
        {
            if(i == NULL) continue;
            q.push(i);
        }
        while (!q.empty())
        {
            ListNode *t = q.top();
            p->next = new ListNode(t->val);
            q.pop();
            if (t->next != NULL)
                q.push(t->next);
            p = p->next;
        }
        return result->next;
    }
};

int main()
{
    Solution solution;
    //ListNode *l1 = new ListNode(1);
    //l1->next = new ListNode(4);
    //l1->next->next = new ListNode(5);
    //ListNode *l2 = new ListNode(1);
    //l2->next = new ListNode(3);
    //l2->next->next = new ListNode(4);
    //ListNode *l3 = new ListNode(2);
    //l3->next = new ListNode(6);
    //vector<ListNode *> ls({l1, l2, l3});
    vector<ListNode *> ls({});
    auto result = solution.mergeKLists(ls);
    while (result != NULL)
    {
        cout << result->val << ' ';
        result = result->next;
    }
}