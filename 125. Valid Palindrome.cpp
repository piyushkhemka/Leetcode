// Using alnum

class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty())
            return true;

        int i = 0;
        int j = s.length()-1;

        while(i<=j) {

            while (!isalnum(s[i])) i++;
            while (!isalnum(s[j])) j--;
            if (i<=j && tolower(s[i++]) != tolower(s[j--]))
                return false;
        }

        return true;


    }
};







--------
class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty())
            return true;

        int i = 0;
        int j = s.length()-1;

        while(i<=j) {

            while (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
                i++;

            while (!((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))
                j--;

            if (i<=j && tolower(s[i++]) != tolower(s[j--])) {
                //  cout << i << " " << j << endl;
                return false;

            }

        }

        return true;


    }
};
