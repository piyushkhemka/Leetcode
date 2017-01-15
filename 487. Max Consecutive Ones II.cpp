class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans = 0;
        int zcurrent = 0;
        bool zero = false;
        int current = 0;
        int i = 0;

        if (nums.empty())
            return 0;

        while(i<nums.size()) {

            if (nums[i] == 0) {

                if (!zero) {
                    zcurrent++;
                    zero = true;
                    ans = max(ans, zcurrent);
                }
                else {
                    zcurrent = current + 1;
                    ans = max(ans, zcurrent);
                }

                current = 0;
            }

            if (nums[i]) {
                current++;
                zcurrent++;
                ans = max(ans, current);
                ans = max(ans, zcurrent);

            }
            i++;
        }
        return ans;

    }
};
