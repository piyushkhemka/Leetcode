class Solution {
public:
    int reverse(int x) {

        long num = 0;
        bool neg = false;
        int copy = x;

        if(x < 0) {
            neg = true;
            x = x * -1;
        }

        while(x) {
            int quo = x%10;
            x = x/10;

            if (INT_MAX - num*10 - quo < 0) {
                num = 0;
                break;
            }

            if(x < 0 && num*10 + quo - INT_MIN > 0) {
                num = 0;
                break;
            }
            num = num*10 + quo;

        }

        if (neg)
            num = -1 * num;

        return num;

    }
};
