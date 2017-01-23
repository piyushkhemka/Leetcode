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
    ListNode *detectCycle(ListNode *head) {

        if (!head)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                slow = head;

                while(slow!=fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }

        }

        return nullptr;

    }
};


-------
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast;

        if(head == NULL)
            return NULL;
        fast = slow = head;

        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                slow = head;

                while(slow!=fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};
