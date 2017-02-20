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

    void helper(TreeNode *root, pair<int,int> &value, int level) {

        if (!root)
            return;

        if (level > value.first) {
            value.first = level;
            value.second = root->val;
        }

        helper(root->left, value, level+1);
        helper(root->right, value, level+1);

    }


public:
    int findBottomLeftValue(TreeNode* root) {

        pair<int, int> value = make_pair(-1,-1); // level, value

        helper(root, value, 0);
        return value.second;

    }
};
