class Solution {
public:
    string countAndSay(int n) {

        if (!n)
            return "";

        n--;

        int a = 1;
        string temp = to_string(a);

        while (n--) {

            int count = 1;
            string newtemp = "";
            int i;

            for (i = 1;i<temp.length();i++) {

                if (temp[i-1] == temp[i])
                    count++;

                else {
                    newtemp += to_string(count) + temp[i-1];
                    count = 1;
                }
            }

            if (i == temp.length()) {
                newtemp += to_string(count) + temp[i-1];
            }

            temp = newtemp;

        }

        return temp;

    }
};
