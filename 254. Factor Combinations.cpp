class Solution {

    void helper(int n, int start, vector<int> temp, vector<vector<int> > &result) {

        if(!n)
            return;

        if(n < start)
            return;

        if(!temp.empty()) {
            temp.push_back(n);
            result.push_back(temp);
            temp.pop_back();
        }


        for(int i = start;i<=n/2;i++) {

            if (n % i == 0) {
                temp.push_back(i);
                helper(n/i, i, temp, result);
                temp.pop_back();
            }
        }

    }

public:
    vector<vector<int>> getFactors(int n) {

        vector<vector<int> > result;
        if(!n)
            return result;

        vector<int> temp;
        helper(n, 2, temp, result);

        return result;



    }
};
