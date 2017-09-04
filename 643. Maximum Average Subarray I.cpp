class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        deque<int> window;
        double ans = INT_MIN;
        double avg = 0.0;
        int sum = 0;
        for(auto i:nums) {

            window.push_back(i);
            sum+=i;

            if(window.size() > k) {
                sum -= window.front();
                window.pop_front();
            }

            if(window.size() == k) {
                avg = double(sum)/double(k);
                ans = max(avg, ans);
            }
        }

        return ans;

    }
};
