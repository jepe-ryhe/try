#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *vHead = new ListNode(0);
    vHead->next = head;
    ListNode *pf = vHead, *ps = vHead;
    for (int i = 0; i < n; i++) {
      pf = pf->next;
    }
    while (pf->next != NULL) {
      pf = pf->next;
      ps = ps->next;
    }
    ps->next = ps->next->next;
    return vHead->next;
  }
};

int main() {
  Solution solution;
  ListNode *head = new ListNode(1);
  head->next = nullptr;
  auto result = solution.removeNthFromEnd(head, 1);
  cout << (result == nullptr);
}