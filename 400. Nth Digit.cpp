class Solution {
public:
    int findNthDigit(int n) {

        if (n <= 9)
            return n;

        int nine = 9;
        long i = 0;
        long copy = n;
        long sum = 0;

        while (copy > 0) {
            ++i;
            sum = nine*pow(10,i-1);
            sum = sum * i;
            copy = copy - sum;
        }

        copy = copy + sum;

        int q = copy / i;
        int r = copy % i;

        long num = 1*pow(10,i-1) + q;
        int ans = 0;

        // cout << num << endl;

        if (r == 0) {
            r = i;
            --num;
        }
        // start from index. r = index and strip away all the remaining digits and then extract the required digit.
        for(int j = r;j<i; ++j) {
            num = num/10;
        }
        ans = num % 10;
        return ans;

    }
};
