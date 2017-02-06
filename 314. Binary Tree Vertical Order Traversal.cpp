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
    vector<vector<int>> verticalOrder(TreeNode* root) {

        vector<vector<int> > result;

        if(!root)
            return result;

        map<int,vector<int> > m;

        queue<pair<TreeNode *,int> > q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            if(m.find(top.second) == m.end())
                m.insert(make_pair(top.second, vector<int> ()));

            m[top.second].push_back(top.first->val);

            if(top.first->left)
                q.push(make_pair(top.first->left, top.second-1));

            if(top.first->right)
                q.push(make_pair(top.first->right, top.second+1));

        }

        for(auto vec: m) {
            result.push_back(vector<int> ());
            result.back() = vec.second;
        }

        return result;

    }
};
