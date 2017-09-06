class Solution {
public:
    int maximumSwap(int num) {

        string str = to_string(num);
        int maxd = -1;
        int index = -1;
        int i = 1;

        while(i < str.length() && str[i-1] >= str[i]) {
            i++;
        }

        if(i == str.length())
            return num;

        for(; i< str.length(); ++i) {
            if(int(str[i] - '0') >= maxd) {
                maxd = int(str[i] - '0');
                index = i;
            }
        }

        for(int i = 0; i<str.length() ; ++i) {
            if(int(str[i] - '0') < maxd) {
                swap(str[i], str[index]);
                break;
            }

        }
        return stoi(str);

    }
};
