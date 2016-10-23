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

    void pathsumrec(TreeNode* root, int sum, vector<vector<int> > &result, vector<int> &cur) {


        if (root == NULL)
            return;
        if (root->val == sum && !root->right && !root->left) {
            cur.push_back(root->val);
            result.push_back(cur);
            cur.pop_back();
            return;
        }

        cur.push_back(root->val);
        pathsumrec(root->left, sum - root->val, result, cur);
        pathsumrec(root->right, sum - root->val, result, cur);
        cout << cur.back() << endl;
        cur.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector< int> > result;
        vector<int> cur;
        pathsumrec(root, sum, result,cur);

        return result;

    }
};
