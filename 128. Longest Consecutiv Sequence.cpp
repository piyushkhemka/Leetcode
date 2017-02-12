class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;

        map<int,int> m;

        int ans = 0;
        int cur = 0;
        int last = INT_MIN;

        for(int i = 0;i<nums.size(); ++i) {
            m[nums[i]] = i;
        }


        for(auto i: m) {

            if (last == INT_MIN) {
                last = i.first;
                cur++;
                ans = 1;
                continue;
            }

            if (i.first == last+1) {
                cur++;
                last = i.first;
                ans = max(ans, cur);
            }
            else {
                ans = max(ans, cur);
                cur = 1;
                last = i.first;
            }
        }

        return ans;


    }
};
