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

    TreeNode* merge(TreeNode* a, TreeNode* b) {

        if(!a && !b)
            return nullptr;

        TreeNode *c;

        if(!a && b) {
            c = b;
            c->left = merge(nullptr, b->left);
            c->right = merge(nullptr, b->right);
            return c;
        }

        else if(a && !b) {
            c = a;
            c->left = merge(a->left, nullptr);
            c->right = merge(a->right, nullptr);
            return c;
        }

        else if (a && b) {
            c = new TreeNode(a->val + b->val);
            c->left = merge(a->left, b->left);
            c->right = merge(a->right, b->right);
            return c;
        }
    }


public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        if(!t1 && !t2)
            return nullptr;

        TreeNode* t3 = merge(t1, t2);
        return t3;

    }
};
