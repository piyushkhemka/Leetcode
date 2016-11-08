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

    void binpath(TreeNode *root, vector<string> &res, string cur) {

        if (!root)
            return;

        if(!cur.empty())
            cur+= "->";

        if(!root->left && !root->right) {
            cur = cur + to_string(root->val);
            res.push_back(cur);
            return;
        }

        binpath(root->left, res, cur + to_string(root->val));
        binpath(root->right, res, cur + to_string(root->val));
    }


public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;

        if (!root)
            return res;

        string cur = "";

        binpath(root, res, cur);

        return res;



    }
};
