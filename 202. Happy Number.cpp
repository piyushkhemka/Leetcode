class Solution {
public:
    bool isHappy(int n) {

        // Based on the observation that except 1 and 7 all single digit numbers are unhappy
        unordered_map<int,int> unhappy = { {4,1},{5,1},{6,1},{8,1},{9,1},{2,1},{3,1},{0,1}};
        if (n == 1 || n == 7)
            return 1;

        if(unhappy[n])
            return false;

        int num = 0;

        while (num != 1) {

            num = 0;

            while(n) {

                num += (n%10) * (n%10);
                n = n/10;
            }
            if (unhappy[num])
                return false;

            n = num;

        }

        return true;



    }
};
------------------
/*

Very smart Solution
https://discuss.leetcode.com/topic/12587/my-solution-in-c-o-1-space-and-no-magic-math-property-involved

*/

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
