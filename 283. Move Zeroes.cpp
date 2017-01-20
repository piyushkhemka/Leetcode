
// More efficient in terms of number of operations

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0;
        int nonzero = 0;

        while (i < nums.size()) {

            if (nums[i])
                swap(nums[nonzero++], nums[i]);

            i++;
        }
    }
};

-------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0;
        int nonzero = 0;

        while (i < nums.size()) {
            if (nums[i])
                nums[nonzero++] = nums[i];
            i++;
        }

        for (int j = nonzero; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};
