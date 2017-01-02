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

    void helper(TreeNode *root, long cursum, long &sum) {

        if(!root)
            return;

        long newsum = cursum*10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            sum += newsum;
            return;
        }

        helper(root->left, newsum, sum);
        helper(root->right, newsum, sum);


    }


public:
    int sumNumbers(TreeNode* root) {

        if(!root)
            return 0;

        long sum = 0;
        helper(root, 0, sum);

        return sum;

    }
};
