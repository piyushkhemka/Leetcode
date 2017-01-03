class Solution {
public:
    int arrangeCoins(int n) {

        // int i = 1;

        // while(n >= 0) {

        //     n = n-i;

        //     if(n < 0)
        //         return i-1;

        //     ++i;

        // }

        // return i;


        long high = long(n);
        long low = 0;

        while(low <= high) {

            long mid = low + (high-low)/2;

            if (mid * (mid + 1) <= (long)2*n)
                low = mid+1;

            else {
                high = mid-1;

            }



        }

        return low-1;

    }
};
