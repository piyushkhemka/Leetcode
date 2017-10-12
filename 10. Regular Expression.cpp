class Solution {
public:
    bool isMatch(string s, string p) {

        if(p.empty())
            return s.empty();

        if(p.length() >1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (!s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p));
        }
        else {
            return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
        }

    }
};
-----------------------------------------------------------------

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for(int i = 0;i<=m;i++) {
            for(int j = 1;j<=n;j++) {

                if(p[j-1]!='*')
                    dp[i][j] = i>0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.') ;
                else {
                     bool patternnotmatch = dp[i][j-2];
                     bool patternmatch = i>0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                    dp[i][j] = patternmatch || patternnotmatch;
                }
            }
        }
        return dp[m][n];

    }
};
