class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
    unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++) {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = i;
            else {
                int j = m[nums[i]];
                if(i-j<=k)
                    return true;
                else {
                    m[nums[i]] = i;
                }
                
            }
        }
        
        return false;
        
    }
};