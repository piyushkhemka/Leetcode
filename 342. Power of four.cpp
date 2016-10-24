class Solution {
public:
    bool isPowerOfFour(int num) {

        long long mask = 1431655765;
        return (num >= 0 && ((num & (num-1)) == 0) && ((num & mask) != 0));

    }
};

//
// 1431655765 = 0101010101010101 .. in 32 bits
//
//
// A better way to validate would be to do (n-1)%3 == 0
