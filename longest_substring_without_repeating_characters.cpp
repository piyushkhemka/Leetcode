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