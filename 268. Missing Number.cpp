class Solution {
public:
    int missingNumber(vector<int>& nums) {

        long sum = 0;

        for(auto num : nums) {

            sum += num;
        }

        int n = nums.size();

        long expectedsum = (n*(n+1))/2;

        return abs(sum - expectedsum);

    }
};
