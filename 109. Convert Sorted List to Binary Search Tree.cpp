
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    TreeNode *helper(ListNode *head, ListNode *last) {

        if (! head)
            return nullptr;

        if (head && last && head == last)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != last && fast->next != last) {

            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode (slow->val);

        root->left = helper(head, slow);
        root->right = helper(slow->next, last);

        return root;

    }


public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head)
            return nullptr;

        TreeNode *root =  helper(head, nullptr);

        return root;

    }
};


--------------
/*
Cheat solution : Put everything in a vector & convert sorted array to a bst.
Likely won't be accepted by any interviewer

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    TreeNode *helper(vector<int> &nums, int start, int end) {

        if (start > end)
            return nullptr;

        int mid = start + (end-start)/2;

        TreeNode *root = new TreeNode (nums[mid]);

        root->left = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end);

        return root;

    }

public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head)
            return nullptr;

        vector<int> nums;

        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }

        TreeNode *root =  helper(nums, 0, nums.size()-1);

        return root;

    }
};
