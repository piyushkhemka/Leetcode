class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

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
                result.push_back(nums[i]);
            }
        }

        return result;
    }

};

------------

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;

        for(int i = 0; i<nums.size(); ) {
            if(nums[i] == i+1) {
                i++;
                continue;
            }

            if(nums[nums[i]-1] == nums[i]) {
                i++;
                continue;
            }

            swap(nums[nums[i]-1] , nums[i]);



        }

        for(int i = 0;i<nums.size(); i++) {
            if(nums[i]!= i+1)
                ans.push_back(nums[i]);
        }

        return ans;

    }
};
