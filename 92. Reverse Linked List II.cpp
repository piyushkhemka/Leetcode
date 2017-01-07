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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if(!head)
            return nullptr;

        if(m == n)
            return head;

        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *onebeforem = nullptr;
        ListNode *mth = nullptr;
        int mcopy = m;

        m--;
        n--;

        while(cur->next && m-- && n--) {
            prev = cur;
            cur = cur->next;
        }

        onebeforem = prev;
        mth = cur;

        while(cur && n--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        if(onebeforem)
            onebeforem->next = cur;

        if(cur)
            mth->next = cur->next;

        cur->next = prev;

        if (mcopy == 1)
            head = cur;

        return head;

    }
};
