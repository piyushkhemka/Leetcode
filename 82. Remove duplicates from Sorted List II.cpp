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

        if (!head)
            return NULL;

        int todelete;

        ListNode *prev, *cur, *next;

        prev = NULL;
        cur = head;

        while (cur->next) {

            next = cur->next;


           if (cur->val == next->val || cur->val == todelete) {

                todelete = cur->val;

                if (prev) {
                    prev->next = next;
                    cur->next = NULL;
                    delete cur;
                    cur = next;

                } else {
                    head = cur->next;
                    cur->next = NULL;
                    delete cur;
                    cur = head;
                }


           }
           else {
               prev = cur;
               cur = cur->next;
           }
        }


        if (cur->val == todelete) {
            if (prev) {
                prev->next = NULL;
                delete cur;
            }
            else {
                head = cur->next;
                delete cur;
            }
        }



    return head;
    }


};
