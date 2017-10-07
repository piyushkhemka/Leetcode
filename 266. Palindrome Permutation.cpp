class Solution {
public:
    bool canPermutePalindrome(string s) {

        unordered_map<char, int> m;

        for(auto i:s) {
            m[i]++;
        }
        int count = 0;
        for(auto i:m) {
            if(i.second % 2 == 1)
                count++;
            if(count > 1)
                return false;
        }

        return true;

    }
};
