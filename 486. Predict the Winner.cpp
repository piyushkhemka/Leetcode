class Solution {

    int helper(vector<int>& nums, int i, int j, vector<vector<int> > &dp) {

        if (i > j || i > nums.size()-1 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];


        int left = nums[i] + min(helper(nums, i+2, j, dp) , helper(nums, i+1, j-1, dp));

        int right = nums[j] + min(helper(nums, i, j-2, dp), helper(nums, i+1, j-1, dp));

        dp[i][j] = max(left, right);

        return dp[i][j];

    }


public:

    bool PredictTheWinner(vector<int>& nums) {

        int i = 0;
        int j = nums.size()-1;

        if(nums.empty())
            return true;

        if(nums.size() == 1)
            return true;

        if(nums.size() == 2)
            return true;

        vector<vector<int> > dp(nums.size(), vector<int> (nums.size(), -1));

        long sum = 0;

        for(auto n: nums)
            sum +=n;

        long playerone = helper(nums, i, j, dp);


        if ( (sum - playerone) <= playerone)
            return true;
        else
            return false;

    }
};
