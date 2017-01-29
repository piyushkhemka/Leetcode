class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length()!=t.length())
            return false;

        unordered_map<char,char> m;
        unordered_map<char, char> m2;

        for(int i = 0;i<s.length(); ++i) {

            if (m.find(s[i]) == m.end()) {

                if (m2.find(t[i])!=m2.end())
                    return false;

                m2[t[i]] = s[i];
                m[s[i]] = t[i];
            }
            else {
                if (t[i]!= m[s[i]])
                    return false;
            }
        }

        return true;

    }
};
