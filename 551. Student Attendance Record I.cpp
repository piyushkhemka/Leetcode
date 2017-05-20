class Solution {
public:
    bool checkRecord(string s) {

        int a = 0;

        if(s.size() < 2)
            return true;

        if (s[0] == 'A')
            a++;

        for(int i = 1; i<s.length(); ++i) {

            if(s[i] == 'A')
                a++;

            if(a > 1)
                return false;

            if(i+1 < s.length() && s[i-1] == s[i] && s[i] == s[i+1] && s[i] == 'L')
                return false;

        }

        return true;


    }
};
