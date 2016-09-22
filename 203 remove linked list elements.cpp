/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;

        ListNode *prev = head;
        ListNode *cur;


        while(prev) {

           if(prev && prev->next && prev->next->val==val) {
               cur = prev->next;
               prev->next = cur->next;
               delete cur;
           }
           else {
               prev = prev->next;
           }
        }

       if(head && head->val == val) {
           head = head->next;
       }
       return head;
    }
};
