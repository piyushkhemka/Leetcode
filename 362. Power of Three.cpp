class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
};

// 1162261467 is the maximum power of 3 (for 32 bit signed integers)
