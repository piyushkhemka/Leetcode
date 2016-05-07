class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = x;
        int a = 0;
        while(n)
        {
            int rem = n % 10;
            a = a*10+rem;
            n = n/10;
        }
        
        if(a == x)
            return true;
        return false;
        
    }
};