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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *cur = head;
        ListNode *todel = head;
        ListNode *prev = nullptr;

        n--;

        while(cur && n--) {
            cur = cur->next;
        }

        while(cur && cur->next) {
            cur = cur->next;
            prev = todel;
            todel = todel->next;
        }

        if (todel == head) {
            prev = todel->next;
            delete todel;
            return prev;
        }

        prev->next = todel->next;

        delete todel;

        return head;


    }
};
