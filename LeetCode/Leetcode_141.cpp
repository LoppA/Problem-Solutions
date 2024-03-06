// https://leetcode.com/problems/linked-list-cycle/
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (!head || !head->next) {
        return false;
      }
      ListNode *slow = head->next;
      ListNode *fast = head->next->next;
      
      while(fast) {
        if (slow == fast) {
          return true;
        }
        if (!fast->next) {
          return false;
        }
        slow = slow->next;
        fast = fast->next->next;
      }
      
      return false;
    }
};
