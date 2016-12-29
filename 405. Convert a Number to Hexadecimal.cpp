class Solution {
public:
    string toHex(int num) {

        if(num == 0)
            return "0";

        int count = 0;

        const char hexa[] = {'0', '1' , '2' , '3' , '4', '5', '6' , '7' ,'8' , '9' , 'a','b','c','d','e','f'};

        string res = "";

        while(num && count < 8) {
            res = hexa[num & 0xf] + res;
            num = num >> 4;
            ++count;
        }

        return res;
    }
};

-------------------

class Solution {
public:
    string toHex(int num) {

        string result;

        char hexa[] = {'a','b','c','d','e','f'};

        unsigned int newnum = (int)num;

        if (!num)
            return "0";

        while(newnum) {

            int r = newnum % 16;

            if(r > 9)
                result = hexa[r - 10] + result;

            else
                result = to_string(r) + result;

            newnum = newnum / 16;

        }

        return result;

    }
};
