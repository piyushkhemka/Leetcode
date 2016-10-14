
void perm(vector<int> &nums, vector<int> &row,vector<vector<int> > &result, int k) {
    if (k == nums.size()-1) {
        row = nums;
        result.push_back(row);
        return ;
    }

    for(int i = k; i<nums.size();++i) {
        swap(nums[i],nums[k]);
        perm(nums,row,result,k+1);
        swap(nums[i],nums[k]);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> row;
        vector<vector<int> > result;
        perm(nums,row,result,0);
        return result;
    }
};
