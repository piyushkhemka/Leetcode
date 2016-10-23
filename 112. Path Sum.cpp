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

    bool hasPathSumRec(TreeNode* root, int sum, int cursum) {

        if (!root)
            return false;

        if (root && !root->left && !root->right && sum == cursum + root->val )
            return true;

        return (hasPathSumRec(root->left, sum, cursum + root->val) || hasPathSumRec(root->right, sum, cursum + root->val));

    }


public:
    bool hasPathSum(TreeNode* root, int sum) {

        if(root == NULL)
            return false;

        return hasPathSumRec(root,sum, 0);



    }
};
