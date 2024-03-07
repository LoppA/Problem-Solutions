// https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      if (!head) {
        return nullptr;
      }
      if (!head->next) {
        return head;
      }
      ListNode *slow = head;
      ListNode *fast = head->next;
      
      while(fast) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
      }
      
      return slow;
    }
};
