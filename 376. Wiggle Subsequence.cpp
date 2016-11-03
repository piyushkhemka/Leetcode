class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();
        if(!n)
            return 0;

        vector<int> a(n,1);
        int temp = INT_MIN;

        // increasing first
        for(int i = 1;i<n;++i) {
            for(int j = 0;j<i;++j) {

                if(a[j]%2 == 0 && nums[i] < nums[j])
                    a[i] = max(a[i], 1+a[j]);

                else if(a[j]%2!=0 && nums[i]>nums[j])
                    a[i] = max(a[i], 1+a[j]);
            }

        }

        temp = a[n-1];
        fill(a.begin(), a.end(), 1);

        // decreasing first
        for(int i = 1;i<n;++i) {
            for(int j = 0;j<i;++j) {

                if(a[j]%2 == 0 && nums[i] > nums[j])
                    a[i] = max(a[i], 1+a[j]);

                else if(a[j]%2!=0 && nums[i]<nums[j])
                    a[i] = max(a[i], 1+a[j]);
            }

        }

        return max(temp,a[n-1]);


    }
};
