class Solution {
public:
    int hammingDistance(int x, int y) {

        int ans = 0;


        for(int i = 0;i<sizeof(x)*8;++i) {

            int xbit = x & 1 << i;
            int ybit = y & 1 << i;

            // cout << i << " " << xbit << " " << ybit << endl;

            if (xbit != ybit)
                ++ans;

        }

        return ans;


    }
};
