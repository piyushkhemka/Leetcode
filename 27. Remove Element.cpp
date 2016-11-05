class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n = nums.size();

        int i = 0;
        int k = 0;

        while(i < n) {
            if(nums[i]!=val) {
                nums[k++] = nums[i++];
            }
            else
                i++;
        }

        nums.resize(k);

        return k;

    }
};
