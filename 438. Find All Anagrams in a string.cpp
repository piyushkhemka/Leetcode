class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;
        vector<int> pat(256,0);
        vector<int> str(256,0);

        for(int i = 0;i<p.length();++i) {
            ++pat[p[i]];
            ++str[s[i]];
        }

        if(pat == str)
            result.push_back(0);

        for(int i = p.length();i<s.length();++i) {
            ++str[s[i]];
            --str[s[i-p.length()]];

            if (pat == str)
                result.push_back(i-p.length()+1);

        }

        return result;
    }
};
