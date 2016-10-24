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

    int pathSumRec(TreeNode* root, int sum) {

        if(root == NULL)
            return 0;

        int rootmatch =  (root->val == sum);
        int left = pathSumRec(root->left, sum - root->val);
        int right = pathSumRec(root->right, sum - root->val);

        return rootmatch + left + right;

    }
    int pathSum(TreeNode* root, int sum) {

        if (root == NULL)
            return 0;

        int rootval =  pathSumRec(root, sum);
        int lefttree = pathSum(root->left, sum);
        int righttree = pathSum(root->right, sum);
        return (rootval + lefttree + righttree);


    }
};
