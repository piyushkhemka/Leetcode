class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        unordered_map<int, int> m;
        int maxlen = 0;
        int cursum = 0;

        for(int i = 0;i<nums.size();++i) {

            cursum += nums[i];

            if(cursum == k)
                maxlen = max(maxlen, i+1);

            if (m.find(cursum-k)!=m.end())
                maxlen = max(maxlen, i-m[cursum-k]);

            else
                m.insert(make_pair(cursum, i));

        }
        
        return maxlen;


    }
};
