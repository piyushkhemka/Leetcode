class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0)
            return 1;

        if(x == 1)
            return 1;
        if(x == -1) {
            if(n%2)
                return -1;
            else
                return 1;
        }


        if(n<0) {
            x = 1/x;
            n = -n;
        }

        if(n == INT_MIN)
            return 0;

        cout << n << endl;
        if(n%2)
            return x*myPow(x*x,n/2);
        else
            return myPow(x*x,n/2);

    }
};
