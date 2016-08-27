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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL)
            return NULL;

        struct ListNode *cur = head;
        struct ListNode *n;

        if(cur->next!=NULL)
            n = cur->next;
        else return head;

        while(n!=NULL) {
            if(cur->val == n->val) {
                cur->next = n->next;
                delete n;
                n = cur->next;
            }
            else {
                cur = cur->next;
                n = n->next;
            }

        }

        return head;


    }
};
