class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int> > result;

        int n = nums.size();
        int power = 2 << (n-1);

        for(int i = 0;i<power; ++i) {
            vector<int> temp;
            for (int j = 0; j<n ; ++j) {
                if (i & 1 << j) {
                    temp.push_back(nums[j]);
                }
            }

            result.push_back(temp);

        }

        if (nums.empty())
            result.push_back(vector<int> ());

        return result;

    }
};


----------------

Recursive Solution


class Solution {

    void helper(vector<int>& nums , vector<vector<int> >  &result, int k, vector<int> &temp) {


        if (k == nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[k]);
        helper(nums,result,k+1,temp);
        temp.pop_back();
        helper(nums,result,k+1,temp);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int> > result;
        vector<int> current;
        helper(nums,result,0, current);
        return result;

    }
};
