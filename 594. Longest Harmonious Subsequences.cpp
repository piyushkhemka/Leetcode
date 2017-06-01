class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> m;
        int ans = 0;

        for(auto i: nums)
            m[i]++;

        for(auto it = m.begin(); it!= m.end(); it++) {

            if (m.find(it->first + 1) != m.end())
                ans = max(ans, it->second + m[it->first + 1]);
        }
        return ans;
    }
};
