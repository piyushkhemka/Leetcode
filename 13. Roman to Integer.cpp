class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> m {
                                  {'D',500},
                                  {'C',100},
                                  {'V',5},
                                  {'X',10},
                                  {'I',1},
                                  {'L',50},
                                  {'M',1000}
                                  };

        int n = s.length();
        int res = 0;
        char last = 'I';
        for(int i = n-1;i>=0;i--) {

            if(m[last] > m[s[i]])
                res = res - m[s[i]];
            else
                res = res + m[s[i]];

            last = s[i];

        }

        return res;


    }
};
