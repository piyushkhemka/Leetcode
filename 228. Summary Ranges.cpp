class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> res;

        if(nums.empty())
            return res;

        string s = "";
        s = s + to_string(nums[0]);

        for (int i = 1;i<nums.size(); ++i) {

            if(nums[i] == nums[i-1] + 1) {

                if (s[s.length()-1] != '>')
                    s = s + "->";

                if (i == nums.size() - 1)
                    s = s + to_string(nums[i]);

                continue;
            }

            if (s[s.length()-1] == '>')
                s = s + to_string(nums[i-1]);

            res.push_back(s);
            s = "";
            s = s + to_string(nums[i]);
        }

        if (!s.empty())
            res.push_back(s);

        return res;



    }
};
