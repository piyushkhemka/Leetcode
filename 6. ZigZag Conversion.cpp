class Solution {
public:
    string convert(string s, int n) {

        if(n < 2)
            return s;

        vector<string> v(n, "");

        int i = 0;
        int k;

        while(i<s.length()) {

            k = 0;

            while(i<s.length() && k < n) {

                v[k] += s[i];
                i++;
                k++;
            }

            k = n-2;

            while(i<s.length() && k > 0) {

                v[k] += s[i];
                k--;
                i++;
            }
        }

        string res = "";

        for (auto str : v) {
            res += str;
        }
        return res;
    }
};
