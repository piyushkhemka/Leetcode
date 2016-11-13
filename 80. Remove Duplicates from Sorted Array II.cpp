class Solution {
public:
    int removeDuplicates(vector<int>& a) {

        int count = 0;

        int i = 1;
        int j = 2;
        int n = a.size();

        if (n < 3)
            return n;

        while(j < n) {

           if (a[j] == a[i] && a[j] == a[i-1]) {
               j++;
           }
           else {

               i++;
               a[i] = a[j];
               j++;
           }

        }

        return i+1;

    }
};
