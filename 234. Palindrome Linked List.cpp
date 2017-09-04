/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    ListNode* reverselist(ListNode *head, ListNode *end) {
        if(!head || !head->next)
            return head;

        ListNode *cur = head;
        ListNode *next = head;
        ListNode *prev = nullptr;
        ListNode *last = end->next;

        while(cur && cur!=last) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }


public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* right = nullptr;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(!fast) { //even linked list
            right = slow;
            slow = prev;
        }
        else { // odd linked list
            right = slow->next;
            slow = prev;
        }

        reverselist(head, slow);

        while(slow && right) {
            if(slow->val != right->val)
                return false;
            slow = slow->next;
            right = right->next;
        }

        if(slow || right)
            return false;

        return true;
    }
};
