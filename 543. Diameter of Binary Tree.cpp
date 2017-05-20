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

    int height(TreeNode *root) {

        if(!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));

    }


    int getdiameter(TreeNode* root) {

        if(!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);
        int ldia = getdiameter(root->left);
        int rdia = getdiameter(root->right);


        int ans = max(left+right, ldia);
        ans = max(ans, rdia);

        return ans;


    }



public:
    int diameterOfBinaryTree(TreeNode* root) {

        return getdiameter(root);

    }
};
------------

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

    int ans = 0;

    int getdiameter(TreeNode* root) {

        if (!root)
            return 0;

        int left = getdiameter(root->left);
        int right = getdiameter(root->right);

        ans = max(ans, left+right);

        return 1 + max(left, right);


    }



public:
    int diameterOfBinaryTree(TreeNode* root) {

        getdiameter(root);
        return ans;

    }
};
