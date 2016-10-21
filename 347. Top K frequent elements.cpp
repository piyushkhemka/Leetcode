class Solution {
public:

struct mycomp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> m;

        for(int i = 0;i<nums.size(); i++) {
            if (m.find(nums[i]) != m.end())
                m[nums[i]] += 1;
            else
                m[nums[i]] = 1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp> minheap;

        for(auto it = m.begin(); it!=m.end(); it++) {
            minheap.push(make_pair(it->first,it->second));
        }

        while(!minheap.empty() && minheap.size() > k)
                minheap.pop();

        vector<int> result;

        while(!minheap.empty()) {
            result.push_back(minheap.top().first);
            minheap.pop();
        }

        return result;

    }
};


// ----------------------------------------------------------------------------
// Neater Solution
// https://discuss.leetcode.com/topic/44313/3-ways-to-solve-this-problem



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        for (auto kv : cnt) {
            pq.push({kv.second, kv.first});
            while (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
