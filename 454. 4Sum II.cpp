class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int,int> ab;
        unordered_map<int,int> cd;
        int res = 0;
        for(int i = 0;i < A.size(); ++i) {
            for(int j = 0 ;j<B.size();++j) {
                ab[A[i] + B[j]]++;
                cd[C[i] + D[j]]++;
            }
        }


        for(auto i = ab.begin();i!=ab.end();++i) {

            auto j = cd.find(- i->first);
            if (j!=cd.end())
                res = res + (j->second * i->second);

        }

        return res;


    }
};
