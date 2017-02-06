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

    void succ(TreeNode *root, TreeNode *p, TreeNode* &s) {

        if (!root)
            return;

        if (p->val < root->val) {
            s = root;
            succ(root->left, p, s);
        }

        else
            succ(root->right, p, s);

        return;
    }



public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

       TreeNode *s = nullptr;

       if (p->right) {

            s = p->right;

            while (s->left)
                s = s->left;

            return s;
        }

       else
            succ(root, p, s);

       return s;

    }
};
