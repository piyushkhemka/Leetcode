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
private:
    bool sym(TreeNode *a, TreeNode *b) {

        if (!a && !b)
            return true;

        else if (!a && b)
            return false;

        else if (a && !b)
            return false;

        else
            return (a->val == b->val) && sym(a->left, b->right) && sym(a->right, b->left);


    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return sym(root->left, root->right);
    }
};
