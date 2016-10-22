/*
Handles

 Whitespaces
 Overflow
 Underflow
 Negative/ Positive numbers
 Non-digits

*/

class Solution {
public:
    int myAtoi(string str) {

        int n = str.length();
        long long num = 0;
        int i = 0;
        bool neg = false;
        while(str[i] == ' ') {
            i++;
        }

         if(str[i] == '-') {
                neg = true;
                i++;
        }
        else if (str[i] == '+')
            i++;

        for( ; i<n ; ++i) {

            if (str[i]-'0' < 0 || str[i] - '0' > 9) {

                if(neg)
                    return num*-1;
                else
                    return num;
            }

            if (INT_MAX - num*10 - (str[i]-'0')  < 0) {

                num = INT_MAX;

                if(neg)
                    num = INT_MIN;

                break;
            }

            num = num*10 + str[i]-'0';
        }

        if(neg)
            num = num * -1;

        return num;

    }
};


// ----------------------------------------------------------------

// Elegant Solution
// https://discuss.leetcode.com/topic/15891/8ms-c-solution-easy-to-understand
int myAtoi(string str) {
    long result = 0;
    int indicator = 1;
    for(int i = 0; i<str.size();)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
        while('0'<= str[i] && str[i] <= '9')
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;
        }
        return result*indicator;
    }
}
