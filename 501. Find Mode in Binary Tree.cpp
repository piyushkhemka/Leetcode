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

    void traverse(unordered_map<int, int> &m, TreeNode* root) {

        if(!root)
            return;

        m[root->val]++;

        traverse(m, root->left);
        traverse(m,root->right);

    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;

        if(!root)
            return result;

        unordered_map<int, int> m;

        traverse(m, root);

        int maxe = INT_MIN;

        for(auto i :m) {
            maxe = max(maxe, i.second);
        }

        for(auto i :m) {
            if(i.second == maxe)
                result.push_back(i.first);
        }

        return result;
    }
};
