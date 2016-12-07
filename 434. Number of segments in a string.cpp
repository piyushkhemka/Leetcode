class Solution {
public:
    int countSegments(string s) {

        string word;
        int c = 0;
        istringstream ss(s);
        while(ss >> word) {
            ++c;
        }

        return c;
    }
};
