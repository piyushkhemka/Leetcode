class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> s(amount+1, INT_MAX);
        s[0] = 0;
        for(int i = 1;i<=amount;i++) {
            for(int j = 0;j<coins.size();j++) {
                if(coins[j]>i)
                    continue;
                
                if(s[i-coins[j]]!=INT_MAX)
                    s[i] = min(s[i] , 1+s[i-coins[j]]);
                
            }
        }
        
        if(s[amount] == INT_MAX)
            s[amount] = -1;
            
        return s[amount];
    }
};