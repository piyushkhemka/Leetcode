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

    bool validbst(TreeNode *root, long long minsofar, long long maxsofar) {

        if (!root)
            return true;

        if ((root->val >= maxsofar) || (root->val <= minsofar)) {
            cout << root->val;
            return false;
        }

        return validbst(root->left,minsofar, root->val) && validbst(root->right, root->val, maxsofar);

    }
public:
    bool isValidBST(TreeNode* root) {

        return validbst(root,LONG_MIN,LONG_MAX);

    }
};
