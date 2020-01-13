#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *result = new ListNode(0);
    ListNode *p = result;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val > l2->val) {
        p->next = new ListNode(l2->val);
        p = p->next;
        l2 = l2->next;
      } else {
        p->next = new ListNode(l1->val);
        p = p->next;
        l1 = l1->next;
      }
    }
    if (l1 != NULL)
      p->next = l1;
    if (l2 != NULL)
      p->next = l2;
    return result->next;
  }
};

int main() {
  Solution solution;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  ListNode *l2 = new ListNode(3);
  auto result = solution.mergeTwoLists(l1, l2);
  while (result != NULL) {
    cout << result->val;
    result = result->next;
  }
}