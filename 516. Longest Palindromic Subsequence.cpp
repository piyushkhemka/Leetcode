class Solution {

//     int lcs(string s, string t, int n, int m) {

//         if(n < 0 || m < 0)
//             return 0;

//         if (s[n] == t[m])
//             return 1 + lcs(s, t, n-1, m-1);
//         else
//             return max(lcs(s, t, n-1, m), lcs(s,t, n, m-1));

//     }

    int lcs(string s, string t, int n, int m) {

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];

    }

public:
    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        return lcs(s,t, s.length(), t.length());

    }
};
