class Solution {
public:

    void genpar(int left, int right, vector<string> &result, const string &cur) {

        if(!left && !right) {
            result.push_back(cur);
            return;
        }

        if(left > 0)
            genpar(left-1,right,result,cur+'(');

        if (right > left)
            genpar(left,right-1,result,cur+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        genpar(n,n,result,"");
        return result;
    }
};
