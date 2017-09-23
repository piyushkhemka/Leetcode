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


-------------------


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(!amount)
            return 0;

        if(coins.empty())
            return -1;

        vector<int> s(amount+1, -1);

        s[0] = 0;

        for(int i = 1; i<= amount; ++i) {
            for(int j = 0; j < coins.size(); ++j) {

                if (coins[j] <= i) {

                    if (s[i-coins[j]]!= -1)
                        s[i] = min( (s[i] == -1? INT_MAX : s[i]) , 1 + s[i-coins[j]] );

                }


            }
        }

        return s[amount];



    }
};

---------------------------


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(!amount)
            return 0;

        vector<int> v(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        v[0] = 0;

        for(int i = 1;i<=amount; ++i) {
            for(int j = coins.size()-1; j>=0 ;--j) {
                if(coins[j] <= i && v[i-coins[j]]!=INT_MAX) {
                    v[i] = min(v[i], 1+ v[i-coins[j]]);
                }
            }

        }

        if (v[amount] == INT_MAX)
            v[amount] = -1;

        return v[amount];

    }
};
