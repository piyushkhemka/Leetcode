class Solution {
public:
    int hIndex(vector<int>& nums) {

        int n = nums.size();

        vector<int> v(n+1, 0);

        for (int i = n-1; i>=0; i--) {

            if (nums[i] >= n)
                ++v[n];
                
            else
                v[nums[i]]++;
        }

        int sum = 0;

         for (int i = n; i>=0; i--) {

                sum += v[i];

                if(i <= sum)
                    return i;
        }

        return 0;


    }
};
