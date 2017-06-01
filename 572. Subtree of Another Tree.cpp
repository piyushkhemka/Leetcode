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

    bool isSame(TreeNode* s, TreeNode* t) {

        if(!s && !t)
            return true;

        if ((!s && t) || (s && !t))
            return false;

        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);

    }



public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        if(!s && !t)
            return true;

        if ((!s && t) || (s && !t))
            return false;

        return isSame(s,t) || isSubtree(s->left, t) || isSubtree(s->right, t);

    }
};
