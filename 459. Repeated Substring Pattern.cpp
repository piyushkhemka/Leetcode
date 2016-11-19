class Solution {
public:
    bool repeatedSubstringPattern(string str) {

        int n = str.length();

        for(int i = 1;i<n;++i) {
            bool match = true;
            string sub = str.substr(0,i);

            for(int j = i; j<n; j = j+i ) {
                if (sub != str.substr(j,i)) {
                    match = false;
                    break;
                }
            }

            if(match)
                return true;

        }

        return false;

    }
};
