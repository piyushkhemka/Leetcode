class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();
        int i = 0;

        while(i<n) {
            while(nums[i]!=i+1) {

                if(nums[i] == nums[nums[i]-1])
                    break;

                swap(nums[i], nums[nums[i]-1]);
            }

            ++i;
        }

        vector<int> result;

        for(int i = 0;i<n;++i) {
            if(nums[i]!=i+1) {
                result.push_back(i+1);
            }
        }

        return result;

    }
};
