29th Dec

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int> > result;
        queue<TreeNode *> q;

        if(!root)
            return result;

        q.push(root);
        int level = -1;
        while(!q.empty()) {
            int count = q.size();
            ++level;

            while(count) {
                TreeNode *cur = q.front();
                q.pop();
                --count;

                if(result.size() < level+1)
                    result.push_back(vector<int> ());

                result[level].push_back(cur->val);


                if(cur->left)
                    q.push(cur->left);

                if(cur->right)
                    q.push(cur->right);

            }
        }

        for(int i = 1; i<result.size(); i=i+2) {
            reverse(result[i].begin(), result[i].end());
        }




        return result;

    }
};

----------------
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

    void helper(vector<vector<int> > &result,TreeNode* root, int level, bool dir) {

        if(!root)
            return;

        if(result.size() < level + 1)
            result.push_back(vector<int> ());

        result[level].push_back(root->val);

        helper(result, root->left, level+1, !dir);
        helper(result, root->right, level+1, !dir);

    }


public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int> > result;
        helper(result, root, 0, true);

        for(int i = 1;i<result.size();i = i+2) {
            reverse(result[i].begin(), result[i].end());
        }

        return result;

    }
};

-----------------------------------
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
