class Solution {
public:
    int titleToNumber(string s) {

        int con[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
        int n = s.length();

        int a = 0;
        long ans = 0;
        for(int i = n-1;i>=0;i--) {
          //  cout << con[s[i]-'A'-0];
            ans+=pow(26,a)*con[s[i]-'A'-0];
            a++;
        }
        return ans;
    }
};
