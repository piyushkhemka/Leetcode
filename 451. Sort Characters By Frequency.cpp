class Solution {
public:
    string frequencySort(string s) {

        string res = "";
        if(s.empty())
            return res;

        vector<pair<int,char> > f(256,{0,0});

        int n = s.length();

        for (int i = 0;i<n;++i) {
            ++f[s[i]].first;
            f[s[i]].second = s[i];
        }

        sort(f.begin(),f.end());
        reverse(f.begin(),f.end());

        for (int i = 0;i<f.size(); ++i) {

            if(f[i].first < 1)
                break;
            while(f[i].first--)
                res += f[i].second;
        }

        return res;

    }
};
