class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result = {-1,-1};

        if (nums.empty() || target > nums.back() || target < nums.front())
            return result;

        auto it = lower_bound(nums.begin(),nums.end(),target);
        auto it2 = lower_bound(nums.begin(),nums.end(), target+1)-1;

        int i = it-nums.begin();
        int j = it2-nums.begin();

        if(i < nums.size() && nums[j] == target) {
            result[0] = i;
            result[1] = j;
        }

        return result;

    }
};


--------
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result = {-1,-1};

        if (nums.empty() || target > nums.back() || target < nums.front())
            return result;

        int low = 0;
        int high = nums.size()-1;

        while(low < high) {

            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;

            else
                high = mid;

        }

        if(nums[low] != target)
            low = -1;

        result[0] = low;

        low = 0;
        high = nums.size()-1;

        while(low < high) {

            int mid = low + (high-low)/2;

            if (nums[mid] > target)
                high = mid;

            else
                low = mid+1;

        }

        if (nums[low] != target)
            low--;

        if (nums[low] != target)
            low = -1;

        result[1] = low;

        return result;

    }
};
