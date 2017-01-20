class Solution {

    int ans = 0;

public:
    int integerReplacement(int n) {

        if (n < 2)
            return ans;

        if (n == INT_MAX)
            return 32;

        if (n == 3) {

            // 3 is an exception because 3 is the only odd number where right path is to go to 2, and not 4 inspite
            // of n+1 being a multiple of 4
            ans += 2;
            return ans;
        }

        ans++;

        if (n & 1) {

            if ((n+1) % 4 == 0)
                integerReplacement(n+1);
            else
                integerReplacement(n-1);
        }

        else
            integerReplacement(n/2);


        return ans;
    }
};






--------------
class Solution {

    int helper(long n, int steps) {

        if (!n)
            return steps;

        if (n==1)
            return steps;

        if (n % 2 == 0)
            return helper(n/2, steps+1);

        else
            return min(helper(n-1, steps+1), helper(n+1, steps+1));

        return steps;

    }


public:
    int integerReplacement(int n) {

        if (!n)
            return 0;

       return helper(long(n), 0);

    }
};
