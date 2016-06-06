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
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
        return NULL;
        
        struct TreeNode *aleft = invertTree(root->left);
        struct TreeNode *aright = invertTree(root->right);
            
            root->right = aleft;
            root->left = aright;

        return root;
        
    }
};