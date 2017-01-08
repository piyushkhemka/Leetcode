class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> result;
        multiset<int> windows;

        if(nums.empty())
            return result;

        if(nums.size() < k)
            return result;

        for(int i = 0;i<nums.size();++i) {

            windows.insert(nums[i]);

            if (windows.size() > k) {
                windows.erase(windows.find(nums[i-k]));
            }

            if(windows.size() == k) {

                auto it = windows.begin();
                advance(it, k/2);

                double med;

                if (k%2 == 1)
                    med = *it;

                else {
                    auto it2 = it--;
                    med = double(*it) + (double(*it2) - double(*it))/2;
                }

                result.push_back(med);
            }

        }

        return result;


    }
};
