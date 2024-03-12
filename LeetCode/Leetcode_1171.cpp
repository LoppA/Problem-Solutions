// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
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
    ListNode* removeZeroSumSublists(ListNode* head) {
      if (!head) {
        return head;
      }
      
      ListNode *_head = new ListNode(0, head);
      ListNode *l = _head;
      ListNode *r = head;
      int sum = r->val;
      
      while(r != nullptr) {
        int _sum = sum;
        while(l != r) {
          if (sum == 0) {
            l->next = r->next;
            break;
          }
          l = l->next;
          sum -= l->val;
        }
        
        l = _head;
        r = r->next;
        sum = r ? _sum + r->val : _sum;
      }
      
      return _head->next;
    }
}
