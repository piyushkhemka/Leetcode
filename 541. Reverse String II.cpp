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
        int len = s.length();

        while(end < len) {

            k = n;

            start = end;

            while(k-- && end < len)
                end++;

            reverse(s, start, end-1);

            end = end + n;


        }

        return s;


    }
};
