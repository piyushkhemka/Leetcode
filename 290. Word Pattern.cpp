class Solution {
public:
    bool wordPattern(string pattern, string str) {

        if(pattern.length() == 0 && str.length() == 0)
            return false;

        unordered_map<char,string> m;
        unordered_map<string, char> m2;

        int i = 0;
        int j = 0;
        int numwords = 0;

        while(i < str.length()) {
            int start = i;

            while(i<str.length() && str[i]!= ' ')
                i++;

            string word = str.substr(start,i-start);


            if (m.find(pattern[j]) != m.end()) {
                if (m[pattern[j]] != word) {
                    return false;
                }
            }

            else {
                m[pattern[j]] = word;

            }

            if (m2.find(word) != m2.end()) {
                if (m2[word] != pattern[j]) {
                    return false;
                }
            }

            else {
                m2[word] = pattern[j];
            }

            ++i;
            ++j;
            ++numwords;

        }
        if (numwords != pattern.length())
            return false;

        return true;
    }


};


// BETTER WAY TO READ WORDS in C++
//
//        string words;
//        istringstream ss(str);
//        while(ss >> words) {
//            cout << words << endl;
//        }
