class NumArray {

private:
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {

        sums.push_back(0);
        for (int i = 0;i<nums.size();i++)
            sums.push_back(nums[i] + sums.back());
    }

    int sumRange(int i, int j) {

        return sums[j+1] - sums[i];

    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
