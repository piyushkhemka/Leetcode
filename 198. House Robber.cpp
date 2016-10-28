class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        else if (n == 1)
            return nums[0];

        else if (n == 2)
            return max(nums[0], nums[1]);


        vector<int> s(n, 0);
        int ans = INT_MIN;

        s[0] = nums[0];

        for (int i = 1;i<n ;++i) {

            s[i] = max(s[i-1], nums[i] + s[i-2] );
            ans = max(s[i], ans);
        }

        return ans;
    }
};


// Smarter solution
// https://discuss.leetcode.com/topic/11110/c-1ms-o-1-space-very-simple-solution

int rob(int num[], int n) {
    int a = 0;
    int b = 0;

    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }

    return max(a, b);
}
