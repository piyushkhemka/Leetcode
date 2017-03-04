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

    map<int, int> m;

    void helper(TreeNode* root) {

        if(!root)
            return;

        m[root->val]++;

        helper(root->left);
        helper(root->right);

    }



public:
    int getMinimumDifference(TreeNode* root) {


        helper(root);
        int ans = INT_MAX;
        int last = INT_MAX;

        for(auto i : m) {

            if(abs(i.first - last) < ans)
                ans = abs(i.first - last);


            last = i.first;
        }

        return ans;


    }
};
