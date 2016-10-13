/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct CompareNode {
     bool operator()(ListNode* const &p1, ListNode* const &p2) {
         return p1->val > p2->val;
     }
 };
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    priority_queue<ListNode*, vector<ListNode*>, CompareNode> min_heap;

    for(auto startoflist : A)
    {
        min_heap.push(startoflist);
    }

    ListNode* result = new ListNode(1);
    ListNode* resultitr = result;

    while(!min_heap.empty())
     {
         ListNode* top = min_heap.top();
         min_heap.pop();

         result->next = top;
         result = result->next;

         if(top->next!=NULL)
            min_heap.push(top->next);
     }

    return resultitr->next;

}
