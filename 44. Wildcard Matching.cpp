/*

Understood the solution from 
https://www.youtube.com/watch?v=3ZDZ-N0EPV0

*/

class Solution {
public:
    bool isMatch(string s, string p) {

        int pn = 0;
        bool first = true;

        // Get rid of consecutive stars. Since they are the same as a single star
        // abc****d is converted to abc*d
        for(int i = 0;i<p.length(); ++i) {

           if(p[i] == '*') {

               if (first) {
                   p[pn++] = p[i];
                   first = false;
               }
           }

           else {
               p[pn++] = p[i];
               first = true;
           }
       }

        int sn = s.length();

        vector<vector<int> > dp(sn+1, vector<int> (pn+1, 0));

        dp[0][0] = 1; // both s and p are empty and thus true.

        if(pn > 0 && p[0] == '*')
            dp[0][1] = 1;

        for(int i = 1;i<=sn;++i){
            for(int j = 1;j<=pn;++j) {

                if (s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                else if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }

        return dp[sn][pn];


    }
};

-------------
class Solution {

    bool helper(string &s, string &p, int sn, int pn, int i, int j, vector<vector<int> > &cache) {

        if (j == pn)
            return i == sn;

        if (j > pn || i > sn)
            return false;

        if (cache[i][j]!=-1)
            return cache[i][j];

        if (p[j]!='*') {

            if (s[i] == p[j] || p[j] == '?') {
                cache[i][j] = helper(s,p,sn,pn,i+1,j+1, cache);
            }
            else {
                cache[i][j] = 0;
            }

            return cache[i][j];
        }

        else {

            while (j<sn-1 && p[j+1] == '*') // in case multiple * are present. They work exactly like a single star.
                j++;

            i--; // to try out the * matching with none case as well.

            while (i < sn) {

                if (helper(s,p,sn,pn,i+1,j+1, cache)) {
                    return true;
                }

                i++;
            }
        }
        cache[i][j] = 0;
        return false;
    }


public:
    bool isMatch(string s, string p) {

        int sn = s.length();
        int pn = p.length();

        if(!sn && !pn)
            return true;

        vector<vector<int> > cache(sn+1, vector<int> (pn+1, -1));
        return helper(s,p, sn, pn, 0,0, cache);
    }
};
