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
    bool traverse(TreeNode *root, int k, unordered_map<int, int> &m) {
        if(!root)
            return false;

        if(m.find(k - root->val)!=m.end())
            return true;

        m[root->val]++;
        return traverse(root->left, k, m) || traverse(root->right, k, m);
    }


public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> m;
        return traverse(root, k, m);
    }
};
