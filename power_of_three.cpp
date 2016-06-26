class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        double val = log10(n)/log10(3);
        
        cout << val << endl;
        cout << floor(val) << endl;
        return floor(val) == val;
        
    }
};