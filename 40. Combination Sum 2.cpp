class Solution {
public:

    void combi(vector<int>& candidates, int target, vector<vector<int> > &result, int k, vector<int> &cur, int sum) {

        if (sum == target) {
            if(find(result.begin(), result.end(), cur) == result.end())
                result.push_back(cur);
            return;
        }

        if (sum > target || k == candidates.size())
            return;

        for(int i = k; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            combi(candidates,target,result,k+1,cur,sum+candidates[i]);
            cur.pop_back();
            ++k;

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int > > result;
        vector<int> cur;
        combi(candidates, target, result, 0, cur ,0);
        return result;
    }
};
