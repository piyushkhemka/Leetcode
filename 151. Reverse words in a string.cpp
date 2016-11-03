class Solution {
private:
    void reverseword(string &s, int i,int j) {
        while(i<j) {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

public:
    void reverseWords(string &s) {
        if(s.empty())
            return;

        int n = s.length();
        int i = 0;
        int k = 0;
        int start = 0;

        int numwords = 0;

        while(true) {
            while(i < n && s[i] == ' ')
                i++;

            if(i == n)
                break;

            if (numwords)
                s[k++] = ' ';

            start = k;
            while(i<n && s[i]!= ' ')
                s[k++] = s[i++];

            reverseword(s,start,k-1);

            numwords++;

        }
        s.resize(k);
        reverseword(s,0,k-1);
    }
};
