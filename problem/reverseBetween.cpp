#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n)
            return head;
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *a = h, *d = h;
        for (int i = 0; i < m - 1; i++)
        {
            a = a->next;
        }
        for (int i = 0; i < n; i++)
        {
            d = d->next;
        }
        ListNode *b = a->next, *c = d->next;
        ListNode *pre = b, *cur = pre->next;
        while (cur != c)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        a->next = d;
        b->next = c;
        return h->next;
    }
};

int main()
{
    Solution solution;
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    auto result = solution.reverseBetween(l, 2, 4);
    while (result)
    {
        cout << result->val << ' ';
        result = result->next;
    }
}