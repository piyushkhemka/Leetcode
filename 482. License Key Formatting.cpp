class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        int kcopy = k;
        string result = "";
        bool kzero = false;

        if(k == 0)
            kzero = true;

        if(s.empty())
            return result;

        for(int i = s.length()-1 ; i>=0 ; --i) {
            
            if (k == 0 && !kzero) {
                result = "-" + result;
                k = kcopy;
            }

            if (isalnum(s[i])) {
                k--;


                result = char(toupper(s[i])) + result;
            }

        }

        int i = 0;
        while(result[i] == '-') i++;

        return result.substr(i);

    }
};
