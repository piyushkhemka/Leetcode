class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty())
            return 0;

        int profit = 0;
        int curmin = prices[0];

        for(auto c : prices) {
            curmin = min(curmin, c);
            profit = max(profit, c - curmin);
        }
        return profit;
    }
};
