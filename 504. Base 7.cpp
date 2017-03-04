class Solution {
public:
    string convertToBase7(int num) {

        if(!num)
            return "0";

        string res = "";
        bool neg = false;

        if (num < 0) {
            neg = true;
            num = -num;
        }

        while(num) {

            res = to_string(num % 7) + res;
            num = num/7;
        }

        if(neg)
            res = "-" + res;

        return res;


    }
};
