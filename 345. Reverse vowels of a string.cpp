class Solution {

private:

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        char temp;

        while(i<j) {

            while(!isVowel(s[i]))
                i++;

            while(!isVowel(s[j]))
                j--;

            if(i<j) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }

        return s;
    }
};
