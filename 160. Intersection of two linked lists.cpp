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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(!headA)
            return NULL;

        if(!headB)
            return NULL;

        int na = 0;
        int nb = 0;

        ListNode *cur = headA;

        while(cur) {
            cur = cur->next;
            na++;
        }

        cur = headB;

        while(cur) {
            cur = cur->next;
            nb++;
        }

        ListNode *a, *b;

        int diff = abs(na-nb);

        if (na > nb) {
            a = headA;
            b = headB;
        }
        else {
            a = headB;
            b = headA;
        }

        while(a && diff--) {
            a = a->next;
        }

        while(a && b) {
            if (a->val == b->val)
                return a;

            a = a->next;
            b = b->next;
        }

        return NULL;

    }
};


// Smarter solution: traverse both at the same time without calculating the
// individual lengths.
// If A's end is reached then point it to B and if B's end is reached then point it
// to head of A. In the second traversal they are guaranteed to collide if there is
// an intersection

// https://discuss.leetcode.com/topic/5527/my-accepted-simple-and-shortest-c-code-with-comments-explaining-the-algorithm-any-comments-or-improvements
