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

    int getleft(TreeNode *root) {
        if(!root)
            return 0;

        int ans = 0;

        while(root->left) {
            ++ans;
            root = root->left;
        }

        return ans;
    }

    int getright(TreeNode *root) {

        if(!root)
            return 0;

        int ans = 0;

        while(root->right) {
            ++ans;
            root = root->right;
        }

        return ans;
    }

public:
    int countNodes(TreeNode* root) {

        if (!root)
            return 0;

        int l = 1 + getleft(root);
        int r = 1 + getright(root);

        if (l == r)
            return pow(2,l) - 1;

        else
            return 1 + countNodes(root->left) + countNodes(root->right);


    }
};
