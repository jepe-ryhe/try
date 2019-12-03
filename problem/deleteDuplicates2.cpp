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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *lp, *rp, *cp;
        ListNode *h = new ListNode(0);
        h->next = head;
        int i = 0;
        cp = h;
        lp = head;
        while (lp)
        {
            for (i = 0, rp = lp->next; rp != NULL; i++, rp = rp->next)
            {
                if (lp->val != rp->val)
                {
                    break;
                }
            }
            if (i == 0)
            {
                cp->next = lp;
                cp = cp->next;
            }
            else if (rp == NULL)
            {
                cp->next = NULL;
                break;
            }
            lp = rp;
        }
        return h->next;
    }
};

int main()
{
    Solution solution;
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(3);
    auto result = solution.deleteDuplicates(l);
    while (l)
    {
        cout << l->val << ' ';
        l = l->next;
    }
}