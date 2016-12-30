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
        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode* root) {

        if(!root)
            return true;

        return isBalanced(root->right) && isBalanced(root->left) && (abs(height(root->left) - height(root->right)) <=1);

    }
};

-------------------
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

    int height(TreeNode *root) {

        if(!root)
            return 0;

        return 1 + max(height(root->left),height(root->right));
    }

public:
    bool isBalanced(TreeNode* root) {

        if (root == NULL)
            return true;

        return (abs(height(root->left) - height(root->right)) < 2) && isBalanced(root->left) && isBalanced(root->right);

    }
};
