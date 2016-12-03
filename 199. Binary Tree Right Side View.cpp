/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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

     void helper(TreeNode *root, vector<int> &result, int level) {

         if(!root)
             return;

         if(result.size() < level + 1)
             result.push_back(root->val);

         helper(root->right, result, level + 1);
         helper(root->left, result, level + 1 );
     }
 public:
     vector<int> rightSideView(TreeNode* root) {
         vector<int> result;
         helper(root,result,0);
         return result;
     }
 };


 ----------------




/*
Note to self : leveloftree needs to be passed as a pointer. Because otherwise,
leveloftree takes the value of the previous self in the recursion tree. The line
leveloftree won't take the value of curlevel unless its state is maintained through a pointer
The other alternative is to drop the variable leveloftree and use
result.size() < curlevel
*/

class Solution {


    void printrightsideview(TreeNode *root, int curlevel, int *leveloftree, vector<int> &result) {
        if(root == NULL)
            return;

        if(curlevel > *leveloftree ) {
            result.push_back(root->val);
            *leveloftree  = curlevel;
        }

        printrightsideview(root->right,curlevel+1,leveloftree,result);
        printrightsideview(root->left,curlevel+1,leveloftree,result);

    }
public:

    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        int m = 0;
        printrightsideview(root, 1, &m, result);
        return result;

    }


};
