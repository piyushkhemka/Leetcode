class Solution {

private:

    int count(string &s, int len, int i, int j) {

        while(i >=0 && j<len && s[i] == s[j]) {
                i--;
                j++;
        }


        return j-i-1;


    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;

        if(!n)
            return "";

        if(n == 1)
            return s;

        int start = -1;

        for (int i = 1;i<n;++i) {


            int even = count(s,n,i-1,i);
            int odd = count(s,n,i-1,i-1);

            if(odd > ans) {
                ans = odd;
                start = (i-1)-ans/2;
            }

            if(even > ans) {
                ans = even;
                start = i - (ans/2);
            }

        }
        cout << ans<<endl;
        cout << start << endl;
        return s.substr(start, ans);



    }
};
