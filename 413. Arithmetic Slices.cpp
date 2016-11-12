class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        int res = 0;

        if (A.size() <= 2)
            return 0;
        int startpoint = 0;
        int diff = (A[1] - A[0]);
        int i;
        for (i = 2;i<A.size(); ++i) {

            if ((A[i]-A[i-1]) == diff)
                continue;
            else {

                int l = i-startpoint;

                // same as (N-1)*(N-2)/2 = sum of n numbers - n - (n-1)
                int s = ((l*(l+1)/2) - 2*l + 1);

                if (s>=0)
                    res += s;

                diff = A[i] - A[i-1];
                startpoint = i-1;
            }

        }

        int l = i-startpoint;
        int s = ((l*(l+1)/2) - 2*l + 1);
        if (s>=0)
            res += s;

        return res;




    }
};
