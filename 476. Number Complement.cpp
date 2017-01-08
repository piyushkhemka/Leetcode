class Solution {
public:
    int findComplement(int num) {

        if(num == 0)
            return 1;

        int i = 31;

        while(!(1 & num >> i)) i--;

        for(;i>=0;--i) {

            num = num ^ (1 << i);
        }

        return num;

    }
};
