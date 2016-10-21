class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {

        vector<vector<string>> result;
        unordered_map<string, vector<string> > m;
        for(int i = 0; i<s.size(); i++) {
            string cur = s[i];
            string copy = cur;
            sort(cur.begin(),cur.end());
            m[cur].push_back(copy);
        }

        for(auto it = m.begin(); it!=m.end() ;it ++) {
            result.push_back(it->second);
        }
        return result;
    }
};
