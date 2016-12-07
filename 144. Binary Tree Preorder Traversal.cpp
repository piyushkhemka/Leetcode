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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;

        if (!root)
            return res;

        TreeNode *cur = root;
        stack<TreeNode *> s;
        s.push(root);

        while(!s.empty()) {

            cur = s.top();
            s.pop();

            res.push_back(cur->val);

            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }

        return res;



    }
};


-------------

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        stack<TreeNode *> s;
        TreeNode *cur = root;

        while(!s.empty() || cur) {
            while(cur) {

                s.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            cur = cur->right;

        }

        return res;
    }
};
