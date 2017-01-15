class Solution {
public:
    string getHint(string secret, string guess) {

        int na = 0;
        int nb = 0;

        unordered_map<char, int> m;

        for(int i = 0; i<secret.length(); ++i) {

            if(i < guess.length() && guess[i] == secret[i]) {
                na++;
                guess[i] = '*';
            }
            else
                m[secret[i]]++;

        }

        for(int i = 0;i<guess.length(); ++i) {

            if (m[guess[i]]) {
                nb++;
                m[guess[i]]--;
            }


        }

        return to_string(na) + "A" + to_string(nb) + "B";


    }
};
