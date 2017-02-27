class Solution {
public:

    struct mycomp {

      bool operator()(pair<int,int> &p1, pair<int,int> &p2 ) {

        if (p1.first < p2.first)
            return true;

        else if (p1.first == p2.first)
            return p1.second > p2.second;

        else
            return false;

      }

    };

    vector<string> findRelativeRanks(vector<int>& nums) {

        vector<pair<int,int> > v;

        for(int i = 0;i<nums.size(); ++i) {
            v.push_back(make_pair(nums[i],i));
        }

        sort(v.begin(), v.end(), mycomp());


        int size = nums.size();
        vector<string> res(size);

        for(int i = 0;i<v.size(); ++i) {

            // cout << v[i].first << " " << v[i].second << endl;

            if (size == 3)
                res[v[i].second] = "Bronze Medal";
            else if (size == 2)
                res[v[i].second] = "Silver Medal";
            else if (size == 1)
                res[v[i].second] = "Gold Medal";
            else
                res[v[i].second] = to_string(size);

            size--;
        }

        return res;

    }
};
