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


----------

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> m;
        string res = "";

        for(int i = 0;i<s.length(); ++i) {
            m[s[i]]++;
        }

        vector<pair<char, int> > v;

        for(auto i:m) {
            v.push_back(make_pair(i.first, i.second));
        }

        sort(v.begin(), v.end(), [] (const pair<char, int> &i1, const pair<char, int> &i2) {return i1.second > i2.second;});

        for(auto i: v) {
            while(i.second--)
                res += i.first;
        }

        return res;

    }
};
