class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        int rem,temp;

        while(n) {
            n--;
            temp = n/26;
            rem = n%26;
            n = n/26;
            result = char(rem + 'A' ) + result;

        }
        return result;

    }
};
