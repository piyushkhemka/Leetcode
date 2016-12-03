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

    void helper(TreeNode *root,vector<vector<int>> &result, int level ) {
        if(!root)
            return;

        if(result.size() < level + 1) {
            result.push_back(vector<int> ());
        }

        result[level].push_back(root->val);

        helper(root->left, result, level+1);
         helper(root->right, result, level+1);


    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int> > result;

        helper(root, result, 0);

        reverse(result.begin(), result.end());
        return result;
    }
};




-------

// Iterative Solution


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;

        if(!root)
            return result;

        queue<TreeNode *> q;

        q.push(root);

        while(!q.empty()) {

            int s = q.size();

            result.push_back(vector<int> ());

            for(int i = 0;i<s;++i) {
                TreeNode* e = q.front();
                q.pop();

                result[result.size()-1].push_back(e->val);

                if(e->left)
                    q.push(e->left);
                if(e->right)
                    q.push(e->right);


            }

        }

        reverse(result.begin(),result.end());
        return result;

    }
};
