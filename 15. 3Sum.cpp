class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int> > result;
        vector<vector<int> > res;

        if(nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        unordered_map<int, int> d;

        for(int i = 0;i<n; ++i) {
            for(int j = i+1;j<n; ++j) {

                d.insert(make_pair(nums[i],i));
                int sumoftwo = nums[i] + nums[j];

                if((d.find(-sumoftwo)!=d.end()) && d[-sumoftwo]!=i && d[-sumoftwo]!=j) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-sumoftwo);
                    sort(temp.begin(), temp.end());
                    result.insert(temp);
                }

                while(j<n-1 && nums[j] == nums[j+1])
                    j++;
            }
        }

        for(auto i: result)
            res.push_back(i);

        return res;



    }
};
