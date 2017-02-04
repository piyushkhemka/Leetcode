class Solution {

    void helper(vector<int>& nums,set<vector<int> > &result, vector<int> &cur, int k) {

        if (k >= nums.size()) {
            result.insert(cur);
            return;
        }

        cur.push_back(nums[k]);
        helper(nums, result, cur, k+1);
        cur.pop_back();
        helper(nums, result, cur, k+1);


    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        set<vector<int> > result;
        vector<int> cur;

        // No need to sort. But OJ needs sorted answers
        sort(nums.begin(), nums.end());

        helper(nums, result, cur, 0);

        vector<vector<int> > res (result.begin(), result.end());

        return res;


    }
};
