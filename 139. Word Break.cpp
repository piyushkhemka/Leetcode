class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {


        unordered_map<string, int> m;

        for(auto words: wordDict)
            m[words]++;

        if (wordDict.empty() || s.empty())
            return false;

        if (m[s])
            return true;

        int n = s.length();

        vector<int> v(n, 0);

        for (int i = 0; i< n; ++i) {

            string word = s.substr(0,i+1);
            if (m[word] || v[i]) {

                v[i] = 1;

                for(int j = i+1; j<n; ++j) {
                    string rightword = s.substr(i+1, j-i);
                    if (m[rightword] || v[j]) {

                        if (j == n-1)
                            return true;

                        v[j] = 1;
                    }
                }

            }

        }

        return v[n-1] == 1;

    }
};

--------

// Brute force recursive solution. Gets TLE. Nice use of recursion though.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        if (wordDict.empty() || s.empty())
            return false;

        int n = s.length()-1;

        for (int i = 1; i<= s.length(); ++i) {

            string str = s.substr(0, i);

            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {

                if (str == s)
                    return true;

                if (wordBreak(s.substr(i,n-i+1), wordDict)) {
                    return true;
                }
            }

        }

        return false;

    }
};
