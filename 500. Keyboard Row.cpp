class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        unordered_map<char, int> m;
        vector<string> result;

        for (char &c : string("qwertyuiop")) {
            m[c] = 1;
            m[char(toupper(c))] = 1;
        }
        for (char &c : string("asdfghjkl")) {
            m[c] = 2;
            m[char(toupper(c))] = 2;
        }
        for (char &c : string("zxcvbnm")) {
            m[c] = 3;
            m[char(toupper(c))] = 3;
        }

        for(auto w: words) {

            if (w.empty()) {
                result.push_back(w);
                continue;
            }
            int val = m[w[0]];
            bool include = true;

            for(int i = 1; i<w.length(); ++i) {

                if (m[w[i]] != val) {
                    include = false;
                    break;
                }

            }

            if (include)
                result.push_back(w);

        }

        return result;

    }

};
