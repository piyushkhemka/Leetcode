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

    TreeNode* helper(vector<int>& nums, int low, int high) {

        if(low > high)
            return nullptr;

        int mid = low + (high-low)/2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = helper(nums, low , mid-1);

        root->right = helper(nums, mid+1, high);

        return root;

    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if(nums.empty())
            return nullptr;

        TreeNode *root =  helper(nums, 0, nums.size()-1);

        return root;



    }
};
