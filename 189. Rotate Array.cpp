class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 2)
            return;

        reverse(nums.begin(),nums.begin() + n-(k % n));
        reverse(nums.begin() + n-(k % n),nums.end());
        reverse(nums.begin(),nums.end());
        return;
    }
};
