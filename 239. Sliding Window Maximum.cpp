// Monotonic Queue datastructure

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;

        if(nums.empty())
            return res;

        deque<int> window; // store indices

        for(int i = 0; i<nums.size(); ++i) {

            while(!window.empty() && window.front() < i-k+1)
                window.pop_front();

            while(!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();

            window.push_back(i);

            if (i >= k-1)
                res.push_back(nums[window.front()]);


        }


        return res;


    }
};



-----------------------
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;

        if(nums.empty())
            return res;

        multiset<int> window;

        for(int i = 0; i<nums.size(); ++i) {

            window.insert(nums[i]);

            while(window.size() > k) {
                window.erase(window.find(nums[i-k]));
            }

            if (window.size() == k) {
                res.push_back(*window.rbegin());
            }
        }


        return res;


    }
};
