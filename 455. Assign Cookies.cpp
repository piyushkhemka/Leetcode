class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ans = 0;
        int gn = g.size();
        int sn = s.size();

        int j = 0;
        int i = 0;

        while(j<sn && i<gn) {

            if (s[j] >= g[i]) {
                ans++;
                j++;
                i++;
            }
            else
                j++;

        }
        return ans;



    }
};
