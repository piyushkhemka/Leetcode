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

    void helper(TreeNode *root, int &sum, bool leftchild) {
        if (!root)
            return;

        if(root->left == nullptr && root->right == nullptr && leftchild)
            sum += root->val;

        helper(root->left, sum, true);
        helper(root->right, sum, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root,sum, false);
        return sum;

    }
};
