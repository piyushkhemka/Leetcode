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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!k)
            return head;

        int n = 0;

        ListNode *onebeforek = head;

        ListNode *cur = head;

        int kcopy = k;

        while(cur && cur->next && k--) {
            cur = cur->next;
            ++n;
        }

        while(cur && cur->next) {
            cur = cur->next;
            onebeforek = onebeforek->next;
            ++n;
        }

        n++;

        if (kcopy > n) {
            k = kcopy % n;
            k = n - k;
            k--;
            onebeforek = head;
            while(k--) {
                onebeforek = onebeforek->next;
            }
        }

        if(kcopy == n)
            return head;

        if(!cur)
            return head;

        cur->next = head;
        head = onebeforek->next;
        onebeforek->next = nullptr;

        return head;
    }
};
