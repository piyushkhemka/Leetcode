class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <2 || k==0)  return false;
        set<int> windows;
        int l = 0;
        for(int i = 0;i<nums.size();i++) {
            if(i-l>k) {
                windows.erase(nums[l]);
                l++;
            }
            
            auto it = windows.lower_bound(nums[i]-t);
            if(it!=windows.end() && *it-t<=nums[i])
                return true;
            
            windows.insert(nums[i]);
        }
        
        return false;
        
    }
};

