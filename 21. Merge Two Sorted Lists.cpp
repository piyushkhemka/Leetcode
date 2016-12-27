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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *result = new ListNode (-1);
        ListNode *cur = result;

        while(l1 && l2) {

            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;

        }

        while(l1) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }

        while(l2) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }

        return result->next;

    }
};
