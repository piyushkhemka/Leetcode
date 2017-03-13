class Solution {
public:
    int findMinDifference(vector<string>& t) {

        vector<long long> temp;

        for(auto c: t) {

            int mins = stoi(string(c.substr(3)));
            int hours = stoi(c.substr(0,2));

            temp.push_back(hours*60 + mins);

        }

        sort(temp.begin(), temp.end());

        long long ans = abs(temp.front() - temp.back());
        ans = min(ans, 1440-ans);

        for(int i = 1; i<temp.size(); ++i) {

            ans = min(ans, abs(temp[i-1] - temp[i]));
            ans = min(ans, 1440-abs(temp[i-1] - temp[i]));

        }

        return ans;


    }
};
