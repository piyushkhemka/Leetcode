class Solution {

    void helper(int n, string result, int left, int right, vector<string> &ans) {

        //cout << result << endl;

        if (left == n && right == n) {
            ans.push_back(result);
            return;
        }

        if (left < n)
            helper(n, result + "(", left+1, right, ans);

        if(left > right)
            helper(n, result + ")", left, right+1, ans);
    }


public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(!n) {
            ans.push_back("");
            return ans;
        }
        helper(n, "", 0, 0, ans);
        return ans;

    }
};

---------
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
