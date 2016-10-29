class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.empty())
            return 0;

        int ans =  INT_MIN;
        vector<int> maxi(nums.size(),1);
        vector<int> mini(nums.size(),1);

        maxi[0] = nums[0] >= 0 ? nums[0]:1;
        mini[0] = nums[0] >=0 ? 1:nums[0];

        ans = max(ans,nums[0]);

        for (int i = 1;i<nums.size();i++) {

            int ma = max(nums[i], max(nums[i]*maxi[i-1], nums[i]*mini[i-1]));
            int mi = min(nums[i], min( nums[i]*maxi[i-1], nums[i]*mini[i-1]));

            maxi[i] = ma;
            mini[i] = mi;

            cout << ma << " " << mi << endl;

            ans = max(ans, max(maxi[i] , mini[i]));

        }

        return ans;

    }
};
