class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.length()-1;
        int j = b.length()-1;

        string result = "";
        int carry = 0;

        while (i>=0 && j>=0) {

            int num =  (a[i] - '0') + (b[j] - '0') + carry;
            carry = num/2;
            num = num % 2;
            result = to_string(num) + result;
            i--;
            j--;
        }

        while (i>=0) {

            int num =  (a[i] - '0') + carry;
            carry = num/2;
            num = num % 2;
            result = to_string(num) + result;
            i--;
        }

        while (j>=0) {

            int num = (b[j] - '0') + carry;
            carry = num/2;
            num = num % 2;
            result = to_string(num) + result;
            j--;
        }


        if (carry) {
            result = to_string(carry) + result;
        }

        return result;
    }
};
