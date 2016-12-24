// Normal string matching. O(mn) time complexity.

class Solution {
public:
    int strStr(string s, string p) {


        int i = 0;
        int j = 0;
        int n = s.length();
        int m = p.length();


        if(m > n)
            return -1;

        if(!m && !n)
            return 0;

        int start = 0;

        while(i<n && j<m) {
            if(s[i] == p[j]) {
                i++;
                j++;
            }
            else {
                j = 0;
                start++;
                i = start;
            }
        }

        if(j == m)
            return start;

        return -1;

    }
};
