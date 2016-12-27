/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

struct mycomp {
    bool operator() (ListNode* &l1, ListNode* &l2) {
        return l1->val > l2->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *head = new ListNode(-1);

        if (lists.empty())
            return head->next;

        priority_queue<ListNode *, vector<ListNode *> , mycomp > mh;

        for(auto i : lists) {
            if (i)
                mh.push(i);
        }


        ListNode *cur = head;

        while (!mh.empty()) {
            ListNode *f = mh.top();
            cur->next = f;
            cur = cur->next;
            mh.pop();
            if (f->next) {
                f = f->next;
                mh.push(f);
            }

        }

        return head->next;


    }
};
