class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        int i = 0;
        int j = 31;

        while(i<j) {

            if (((n >> i) & 1) != ((n >> j) & 1))
                n = (n ^ (1 << i | 1 << j ));

            i++;
            j--;
        }

        return n;
    }
};
