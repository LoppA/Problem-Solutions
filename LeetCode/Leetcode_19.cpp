// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      stack<ListNode *> s;

      ListNode* _head = new ListNode();
      _head->next = head;


      ListNode *l = _head;
      ListNode *r = _head;

      while(n--) {
        r = r->next;
      }

      while(r->next) {
        l = l->next;
        r = r->next;
      }

      ListNode* prev = l;
      ListNode* dlt = prev->next;

      prev->next = dlt ? dlt->next : nullptr;

      if (dlt) {
        delete dlt;
      }

      return _head->next;
    }
};
