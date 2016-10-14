class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.empty())
            return;

        if(nums.size() == 2) {
            swap(nums[0],nums[1]);
            return;
        }

        int i;
        for(i = nums.size()-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        reverse(nums.begin() + i+ 1, nums.end());
        if(i == -1)
            return;
        auto nexthigh = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
     //   cout << *nexthigh;
        swap(nums[i], *nexthigh);

    //    sort(++nexthigh, nums.end());


    }
};
