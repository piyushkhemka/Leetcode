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
    ListNode* swapPairs(ListNode* head) {

        if(!head)
            return nullptr;

        if(!(head->next))
            return head;

        ListNode *newhead = head->next;
        ListNode *cur = head;
        ListNode *next;
        ListNode *prev = nullptr;

        while(cur && cur->next) {
            next = cur->next;
            cur->next = next->next;
            next->next = cur;

            if (prev) {
                prev->next = next;
            }
            prev = cur;
            cur = cur->next;
        }
        return newhead;
    }
};
