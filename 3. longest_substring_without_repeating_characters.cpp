class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;

        vector<int> a(256,-1);
        int start,maxlength;
        start = -1;
        maxlength = INT_MIN;
        for(int i = 0;i<s.length();i++) {

            if(a[s[i]] > start)
                start = a[s[i]];

            a[s[i]] = i;
            maxlength = max(maxlength,i-start);

        }
        return maxlength;

    }
};


--------

// Revisited problem after many days


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        if(!n)
            return 0;
        if (n < 2)
            return 1;

        int start = -1;
        int end = 0;
        int ans = 0;

        vector<int> a(256,-1);

        for (int i = 0;i<n;++i) {

            if(a[s[i]] > start) {
                ans = max(ans, end-start);
                start = a[s[i]];
            }
            a[s[i]] = i;
            end = i;
            ans = max(ans, end-start);

        }
        return ans;
    }
};
