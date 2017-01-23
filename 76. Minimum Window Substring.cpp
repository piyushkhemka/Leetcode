class Solution {
public:
    string minWindow(string s, string t) {

        if(s.empty() || t.empty())
            return "";
            
        unordered_map<char, int> m;

        for(auto c:t) {
            m[c]++;
        }

        int n = s.length();
        int end = 0;
        int start = 0;
        int minlen = INT_MAX;
        int counter = t.length();
        string result = "";

        while(end < n) {

            if(m[s[end]] > 0)
                counter--;

            m[s[end]]--;

            end++;

            while (counter == 0) {

                if (end - start < minlen) {
                    minlen = end-start;
                    result = s.substr(start, minlen);
                }
                m[s[start]]++;

                if(m[s[start]] > 0)
                    counter++;

                start++;
            }

        }

        return result;


    }
};
