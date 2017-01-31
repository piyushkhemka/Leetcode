class Solution {

    void helper(vector<int>& nums, int k, int n, set<vector<int> > &result, vector<int> &cur) {

        if (k>n)
            return;

        if (cur.size() > 1)
            result.insert(cur);

        for(int i = k;i<n;++i) {

            if (cur.empty() || nums[i] >= cur.back()) {
                cur.push_back(nums[i]);
                helper(nums,i+1,n,result,cur);
                cur.pop_back();
            }
        }
    }


public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int> > result;
        vector<int> cur;
        helper(nums, 0, nums.size(), result, cur);
        vector<vector<int> > ans (result.begin(), result.end());
        return ans;

    }
};
