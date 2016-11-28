class Solution {
public:
    int longestPalindrome(string s) {


        unordered_map<char,int> m;
        int sum = 0;

        for(auto c: s) {
            m[c] += 1;
        }
        int single = 0;
        for(auto i : m) {
            
            cout << i.first << " " << i.second << endl;
            if(i.second % 2 == 0)
                sum = sum + (i.second);
            else {
                sum = sum + i.second - 1;
                single = 1;
            }

            if(!single)
                single = i.second % 2;

        }

        if(single)
            ++sum;

        return sum;


    }
};
