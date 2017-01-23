class Solution {
public:
    int trailingZeroes(int n) {
        long five = 5;
        long ans = 0;
        while(five <= n) {
            ans += n/five;
            five = five * 5;
        }
        return ans;

    }
};
