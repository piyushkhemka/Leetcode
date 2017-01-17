class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        int ans = 0;

        if(nums.size() < 2)
            return 0;

        for(int i = 0;i<sizeof(nums[0])*8;++i) {
            int nzero = 0;
            int none = 0;
            for(auto n : nums) {
                if ((n >> i) & 1)
                    none++;
                else
                    nzero++;
            }
            ans += (nzero*none);
        }
        return ans;
    }
};
