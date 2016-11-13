class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if (n < 1)
            return 0;
        int i = 1;
        int j = 1;

        while(j<n) {

            if (a[j] == a[j-1])
                j++;

            else
                a[i++] = a[j++];

        }

        return i;

    }
};
