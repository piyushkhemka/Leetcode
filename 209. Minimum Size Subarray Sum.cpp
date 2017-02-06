class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int n = nums.size();

        if(!n)
            return 0;

        int start = 0;
        int end = 0;
        int sum = 0;
        int minlen = INT_MAX;

        while(start < n) {

            if (sum < s) {
                sum += nums[start];
                start++;
            }

            while (sum >=s) {
                minlen = min(minlen, start-end);
                sum -= nums[end];
                end++;
            }

        }

        if(minlen == INT_MAX)
            minlen = 0;

        return minlen;



    }
};
