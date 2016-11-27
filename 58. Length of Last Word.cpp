class Solution {
public:
    int lengthOfLastWord(string s) {

        istringstream ss(s);
        string word;
        int n = 0;
        while(ss >> word) {
            n = word.length();
        }

        return n;

    }
};

// Non istringstream solution
class Solution {
public:
    int lengthOfLastWord(string s) {


        int i = s.length()-1;
        int n;

        while(s[i] == ' ') {
            i--;
        }
        n = i;

        while(i>=0 && s[i]!= ' ')
                i--;

        return n-i;

    }
};
