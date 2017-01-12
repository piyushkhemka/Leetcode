/*
https://discuss.leetcode.com/topic/74781/java-solution-with-an-array
if we meet 1 then next number to put is a single number,
if we meet 2 then next number must be written twice.
*/

class Solution {
public:
    int magicalString(int n) {

        if (!n)
            return 0;

        int val = 1;
        int index = 2;
        vector<int> v (n+1);
        int count = 1; //for the starting 1

        for(int i = 2;i<=n, index <=n;++i) {

            val = val == 1? 2 : 1; // flip values

            v[index++] = val;

            if(val == 1)
                count++;

            if (index > n)
                break;

            if (v[i] == 2) {

                v[index++] = val;

                if(val == 1)
                    count++;

                if (index > n)
                    break;

            }
        }

        return count;


    }
};
