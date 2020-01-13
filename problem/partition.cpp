#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (!head || !(head->next))
      return head;
    ListNode *l = new ListNode(0);
    ListNode *r = new ListNode(0);
    ListNode *p = head, *lp = l, *rp = r;
    while (p) {
      if (p->val < x) {
        lp->next = p;
        lp = lp->next;
      } else {
        rp->next = p;
        rp = rp->next;
      }
      p = p->next;
    }
    lp->next = r->next;
    rp->next = NULL;
    return l->next;
  }
};

int main() {
  Solution solution;
  ListNode *l = new ListNode(1);
  l->next = new ListNode(4);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(2);
  l->next->next->next->next = new ListNode(5);
  l->next->next->next->next->next = new ListNode(2);
  auto result = solution.partition(l, 3);
  while (result) {
    cout << result->val << ' ';
    result = result->next;
  }
}