class Solution {

    void reverse(string &s, int i ,int j) {

        if (j >= s.length())
            j = s.length() - 1;

        while( i<=j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }


public:
    string reverseStr(string s, int k) {

        int n = k;

        int start = 0;
        int end = 0;

        for(int i = 0; i<s.length(), end < s.length(); i++) {

            k = n;

            start = end;

            while(k-- && end < s.length())
                end++;

            reverse(s, start, end-1);

            start = end;

            k = n;
            while(k-- && end < s.length()) {
                end++;
            }

        }

        return s;


    }
};
