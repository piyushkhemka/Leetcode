class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result;
        int n = nums.size();
        
        for(int i = 0; i<n; i++)
            m.insert(make_pair(nums[i], i));
            
        for(int i = 0; i<n; i++) {
            int key = target-nums[i];
            auto it = m.find(key);
            if(it != m.end() && it->second != i) {
                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        
        return result;
        
    }
};

