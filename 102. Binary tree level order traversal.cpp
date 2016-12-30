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
The solution is easy to understand but has a bad time complexity.
Better solutions can be found at :
https://leetcode.com/discuss/15521/one-of-c-solutions-preorder
https://leetcode.com/discuss/77205/c-4ms-simple-recursive-solution
-------

// Iterative solution


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int > > res;

        if (!root)
            return res;

       queue<TreeNode *> q;
       q.push(root);
       int level = -1;
       while(!q.empty()) {

           level++;
           int count = q.size();

           while(count) {
               TreeNode *cur = q.front();
               q.pop();
               --count;

               if(res.size() < level+1)
                    res.push_back(vector<int> ());


               res[level].push_back(cur->val);

               if(cur->left) {
                   q.push(cur->left);
               }

               if(cur->right) {
                   q.push(cur->right);
               }


           }

       }

       return res;

    }
};




--------
 */
29th Dec 2016
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

     void helper(vector<vector<int > > &res, TreeNode *root, int level) {

         if(!root)
             return;

         if(res.size() < level+1)
             res.push_back(vector<int> ());

         res[level].push_back(root->val);


         helper(res, root->left, level+1);
         helper(res, root->right, level+1);
     }

 public:
     vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int > > res;

         if (!root)
             return res;

         helper(res, root, 0);
         return res;
     }
 };


-----

// 14th November 2016

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

    void traverse(TreeNode *root, vector<vector<int> > &result, int level) {

        if (!root)
            return;

        if (result.size() < level + 1)
            result.push_back(vector<int> ());

        result[level].push_back(root->val);

        traverse(root->left, result, level+1);
        traverse(root->right, result, level+1);

    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int> > result;

        traverse(root, result, 0);

        return result;

    }


};



 ------
class Solution {
public:
vector<vector<int> > res;

    int heightTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        return max(1+(heightTree(root->left)+1) ,1 + (heightTree(root->right)+1));
    }


    void levelordertraversal(int level,TreeNode* root,int originallevel  ) {

        if(root == NULL)
            return;

        if(level < 0)
            return;

        else if(level == 0) {


            if(res.size() < originallevel+1) { // res.size refers to the number of vector<int> in this 2d vector and not
                                                // number of items in it. Ex: [[1],[2,3]] . Size is 2 and not 3 because
                                                // two lists exist and not three.
                vector<int> temp;
                temp.push_back(root->val);
                res.push_back(temp);
            }
            // If a list doesn't exist in this vector of vectors, then first insert it. If it does, then
            // directly access it and push back a value as done in else block
            else
            res[originallevel].push_back(root->val);
        }

        else {
        levelordertraversal(level-1,root->left,originallevel);
        levelordertraversal(level-1,root->right,originallevel);
        }
    }


    vector<vector<int>> levelOrder(TreeNode* root) {


    int n = heightTree(root);

    for(int i = 0;i< n;i++)
    {
        levelordertraversal(i,root,i);
    }

    vector< vector<int> >::iterator row;
    vector<int>::iterator col;

    for(row = res.begin();row!=res.end();row++)
       {
           for(col = row->begin(); col!= row->end() ; col++)
                {
                   cout<< *col;
                }
            cout<<endl;
       }
       return res;
    }
};
