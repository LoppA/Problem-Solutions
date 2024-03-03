// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      stack<ListNode *> s;
      
      ListNode* _head = new ListNode();
      _head->next = head;
      
      ListNode* node = _head;
      while(node) {
        s.push(node);
        node = node->next;
      }
      
      while(--n) {
        s.pop();
      }
      
      node = s.top();
      s.pop();
      ListNode *prev = s.top();
      ListNode *nxt = node->next;
      
      prev->next = nxt;
      
      return _head->next;
    }
};
