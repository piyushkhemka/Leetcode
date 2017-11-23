class Solution {

    bool selfdivide(int num) {

        int n = num;

        while(num) {

            int digit = num%10;
            num = num/10;

            if(digit == 0 || n % digit !=0)
                return false;
        }

        return true;

    }


public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> ans;

        for(int i = left;i<=right;i++) {

            if(i%10 == 0)
                continue;

            if(selfdivide(i))
                ans.push_back(i);
        }

        return ans;

    }
};
