#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode *tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return tmp;
  }
};

int main() {
  Solution solution;
  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  auto result = solution.swapPairs(l);
  while (result != NULL) {
    cout << result->val;
    result = result->next;
  }
}