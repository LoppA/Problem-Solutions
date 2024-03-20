// https://leetcode.com/problems/merge-in-between-linked-lists/
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      ListNode *l = list1;
      ListNode *r = list1;
      
      for (int i = 0; i < a-1; i++) {
        l = l->next;
      }
      ListNode *d = l->next;
      for (int i = 0; i <= b; i++) {
        r = r->next;
      }
      
      while(d != r) {
        ListNode* nxt = d->next;
        delete(d);
        d = nxt;
      }
      
      l->next = list2;
      while(list2->next) {
        list2 = list2->next;
      }
      list2->next = r;
      
      return list1;
    }
};
