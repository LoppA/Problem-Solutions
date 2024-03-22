// https://leetcode.com/problems/palindrome-linked-list/
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
  
    ListNode *reverse(ListNode* head) {
      ListNode* prev = nullptr;
      
      while(head) {
        ListNode* nxt = head->next;
        
        head->next = prev;
        prev = head;
        head = nxt;
      }
      
      return prev;
    }
  
public:
    bool isPalindrome(ListNode* head) {
      ListNode *slow = head, *fast = head;
      while(fast) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
      }
      
      ListNode* tail = reverse(slow);
      
      while(tail) {
        if (tail->val != head->val) {
          return false;
        }
        head = head->next;
        tail = tail->next;
      }
      
      return true;
    }
};
