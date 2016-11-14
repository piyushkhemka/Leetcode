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
    void zigzag(TreeNode *root, vector<vector<int> > &result, int level) {

        if (!root)
            return;

        if (result.size() < level + 1)
            result.push_back(vector<int> ());

        if(level % 2)
            result[level].push_back(root->val);
        else
            result[level].insert(result[level].begin(), root->val);

         zigzag(root->right, result,  level+1);
         zigzag(root->left, result,  level+1);


    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int> > result;

        zigzag(root, result, 0);

        return result;

    }
};
