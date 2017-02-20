class Solution {
public:
    bool detectCapitalUse(string word) {

        bool small = false;
        bool big = false;

        if (word.size() <= 1)
            return true;

        if (islower(word[0]))
            small = true;

        else if (isupper(word[0])) {
            big = true;

            if (islower(word[1])) {
                big = false;
                small = true;
            }
        }

        for(int i = 1;i<word.length(); ++i) {

            if (small && islower(word[i]))
                continue;

            else if(big && isupper(word[i]))
                continue;

            else
                return false;

        }

        return true;

    }
};
