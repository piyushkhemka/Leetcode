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
    int kthSmallest(TreeNode* root, int k) {

        if (!root)
            return -1;

        stack<TreeNode *> s;

        while(root || !s.empty()) {

            while(root) {
                s.push(root);
                root = root->left;
            }

            TreeNode *p = s.top();
            s.pop();
            k--;

            if (k == 0)
                return p->val;

            root = p->right;
        }
        return -1;

    }
};


// Recursive:

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
    void helper(TreeNode *root, int &k, int &result) {

        if (!root)
            return;

        if (root->left != NULL)
            helper(root->left, k, result);

        k--;

        if (k == 0) {
            result = root->val;
            return;
        }

        if(root->right != NULL)
            helper(root->right, k, result);

    }

public:
    int kthSmallest(TreeNode* root, int k) {

        int result = 0;

        helper(root,k, result);

        return result;

    }
};
