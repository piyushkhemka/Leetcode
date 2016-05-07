class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2 ) return nums.size();
        vector<int> a(nums.size(),1);
        int maxans = INT_MIN;
        
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j] < nums[i])
                a[i] = max(a[i], 1+a[j]);
                maxans = max(maxans,a[i]);
            }
        }
        return maxans;
        
    }
};