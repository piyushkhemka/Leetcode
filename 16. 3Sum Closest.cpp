class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        if(n < 3)
            return 0;

        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for(int i = 0;i<n; ++i) {

            int front = i+1;
            int back = n-1;

            while(front < back) {

                int sum = nums[i] + nums[front] + nums[back];

                if(abs(target - sum) < abs(target - ans))
                    ans = sum;

                if (sum > target)
                  back--;

                else if (sum < target)
                    front++;

                else {
                    ans = target;
                    return ans;
                }

            }


        }
        return ans;

    }


};
