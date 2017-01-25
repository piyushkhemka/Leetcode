class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (nums.empty())
            return -1;

        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {

            int mid = low + (high - low)/2;

            if (nums[mid] == target)
                return 1;

// same as when duplicates not allowed. Except when duplicates do occur there
// is a chance that something like 1 3 1 1 1 will occur which warrants this check
// Time complexity in worst case will be 0(n)
            else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }

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

        return 0;

    }
};
