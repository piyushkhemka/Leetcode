class Solution {
public:
    int distributeCandies(vector<int>& candies) {

        if (candies.empty())
            return 0;

        int n = candies.size();
        int ans;

        unordered_map<int, int> m;

        for(auto i:candies) {
            m[i]++;
        }

        ans = min(int(m.size()), n/2);

        return ans;
    }
};

--------------------------------------------------------
class Solution {
public:
    int distributeCandies(vector<int>& candies) {

        if (candies.empty())
            return 0;

        int n = candies.size();
        int ans;

        unordered_map<int, int> m;

        for(auto i:candies) {
            m[i]++;
        }

        if(m.size() <= n/2)
            ans = m.size();

        else {
            if(n % 2)
                ans = n/2 + 1;
            else
                ans = n/2;
        }

        return ans;
    }
};
