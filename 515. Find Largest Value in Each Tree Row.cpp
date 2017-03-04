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

    void helper(TreeNode* root, int level, vector<int> &result) {

        if (!root)
            return;

        if (level >= result.size())
            result.push_back(INT_MIN);

        if (root->val >  result[level])
            result[level] = root->val;

        helper(root->left, level+1, result);
        helper(root->right, level+1, result);

    }


public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        helper(root, 0, result);
        return result;

    }
};
