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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        if(!root)
            return res;

        stack<TreeNode *> s;
        TreeNode *cur = root;

        while(cur || !s.empty()) {

            while(cur) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            res.push_back(cur->val);

            cur = cur->right;
        }
        return res;
    }
};

-------------------------------------------
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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode *> s;

        if(!root)
            return res;

        TreeNode *cur = root;

        while(!s.empty() || cur!=NULL) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode *p = s.top();
            s.pop();
            res.push_back(p->val);
            if(p->right) {
                cur = p->right;
            }
        }

        return res;


    }
};
