class Solution {
public:
    string addStrings(string num1, string num2) {

        if(num1.empty() && num2.empty())
            return "";

        if(num1.empty())
            return num2;

        if(num2.empty())
            return num1;

        int n = num1.length()-1;
        int m = num2.length()-1;
        string result = "";

        int carry = 0;
        int sum = 0;

        while(n>=0 && m>=0) {
            int curdigit = int(num1[n]-'0') + int(num2[m]-'0') + carry;
            carry = curdigit / 10;
            result = char(curdigit % 10 + '0') + result;
            --n;
            --m;
        }

        while(n>=0) {
            int curdigit = int(num1[n]-'0') + carry;
            carry = curdigit / 10;
            result = char(curdigit % 10 + '0') + result;
            --n;
        }

        while(m>=0) {
            int curdigit = int(num2[m]-'0') + carry;
            carry = curdigit / 10;
            result = char(curdigit % 10 + '0') + result;
            --m;
        }

        if(carry)
            result = char(carry + '0') + result;

        return result;



    }
};
