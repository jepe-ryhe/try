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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *s = new ListNode(0);
        ListNode *p = s;
        p->next = new ListNode(0);
        int succ = 0, tmp = 0;
        while (l1 && l2)
        {
            p = p->next;
            tmp = l1->val + l2->val + succ;
            succ = tmp / 10;
            p->val = tmp % 10;
            p->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            p = p->next;
            tmp = l1->val + succ;
            succ = tmp / 10;
            p->val = tmp % 10;
            p->next = new ListNode(0);
            l1 = l1->next;
        }
        while (l2)
        {
            p = p->next;
            tmp = l2->val + succ;
            succ = tmp / 10;
            p->val = tmp % 10;
            p->next = new ListNode(0);
            l2 = l2->next;
        }
        if (succ)
        {
            p->next->val = succ;
        }
        else
        {
            p->next = NULL;
        }
        return s->next;
    }
};

int main()
{
    ListNode *a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    ListNode *b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);
    Solution s;
    auto r = s.addTwoNumbers(a, b);
    while (r)
    {
        cout << r->val << "->";
        r = r->next;
    }
}