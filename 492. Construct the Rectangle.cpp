class Solution {


public:
    vector<int> constructRectangle(int area) {

        vector<int> res (2,0);

        if(!area)
            return res;

        int l = area;
        int w = 1;
        int i = 2;

        while(l >= w) {

            if ((l*w) == area) {
                res[0] = l;
                res[1] = w;

                if (l == w)
                    break;
            }

            l = area / i;

            if (l)
                w = area / l;
            else
                return res;

            i++;

        }

        return res;

    }
};
