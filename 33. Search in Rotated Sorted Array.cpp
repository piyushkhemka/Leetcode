class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.empty())
            return -1;

        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {

            int mid = low + (high - low)/2;

            if (nums[mid] == target)
                return mid;

            else if (nums[low] <= nums[mid]) { // check if the 1st half of array is sorted
                
                if (nums[mid] > target && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid+1;
            }

            else { // 2nd half of array is sorted

                if (nums[mid] < target && target <= nums[high]) // now find whether the target num lies in the sorted half
                    low = mid+1;
                else
                    high = mid-1;

            }
        }

        return -1;

    }
};
