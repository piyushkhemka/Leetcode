class Solution {
public:
    int minMoves2(vector<int>& nums) {


        sort(nums.begin(),nums.end());
        int n = nums.size();

        int m = (n-1)/2;

        int sum = 0;

        for(auto a:nums) {

            if(a == nums[m])
                continue;

            sum += abs(nums[m] - a);

        }

        return sum;



    }
};
