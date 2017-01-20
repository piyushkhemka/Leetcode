class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int> > result;

        if(!n)
            return result;

        result.push_back(vector<int> ());
        result[0].push_back(1);

        for(int i = 1;i<n; ++i) {

            if (result.size() < i + 1)
                result.push_back(vector<int> ());

            result[i].push_back(result[i-1].front());

            int j = 1;

            while(j < result[i-1].size()) {
                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
                j++;
            }


            result[i].push_back(result[i-1].back());


        }

        return result;


    }
};
