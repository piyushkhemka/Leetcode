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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root)
            return root;

        if(key > root->val)
            root->right =  deleteNode(root->right,key);

        else if (key < root->val)
            root->left =  deleteNode(root->left, key);

        else {

            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            else if (root->left == nullptr && root->right) {

                TreeNode *cur = root->right;
                delete root;
                return cur;

            }

            else if (root->right == nullptr && root->left) {
                TreeNode *cur = root->left;
                delete root;
                return cur;
            }

            else {
                TreeNode *cur = root->right;
                while(cur->left) {
                    cur = cur->left;
                }


                cout << cur->val << endl;

                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);

            }
        }

        return root;


    }
};
