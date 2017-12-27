
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode *ltemp = l1, *rtemp = l2, *now = res, *father = res;
    int pos = 0;
    while (ltemp || rtemp) {
      int l = 0, r = 0;
      if (ltemp) l = ltemp->val;
      if (rtemp) r = rtemp->val;
      now->val = (l + r + pos) % 10;
      pos = (l + r + pos) / 10;
      if (ltemp) ltemp = ltemp->next;
      if (rtemp) rtemp = rtemp->next;
      father = now;
      now->next = new ListNode(0);
      now = now->next;
    }
    if (pos != 0) {
      now->val = pos;
    } else {
      delete now;
      father->next = NULL;
    }
    return res;
  }
};