class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans = 0;
        int cur = 0;

        for(auto num : nums) {

            if(num) {
                cur++;
                ans = max(ans,cur);
            }

            else {
                cur = 0;
            }
        }

        return ans;


    }
};
