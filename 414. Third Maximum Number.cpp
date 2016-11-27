class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;

        for(auto num : nums) {
            if (num > max3 && num!=max2 && num!= max1) {
                max3 = num;
                if (max3 > max2) {
                    swap(max2,max3);
                    if(max2 > max1)
                        swap(max1,max2);
                    }
                }
        }

        if (max3 == LONG_MIN)
            max3 = max1;
        return max3;
    }
};
