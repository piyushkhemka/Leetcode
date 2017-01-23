class Solution {
public:
    int hIndex(vector<int>& c) {

        if (c.empty())
            return 0;

        int n = c.size();

        int low = 0;
        int high = n-1;

        while(low <= high) {

            int mid = low + (high-low)/2;

            if (c[mid] == (n-mid))
                return n-mid;

            else if (c[mid] > (n-mid))
                high = mid - 1;

            else
                low = mid + 1;
        }

        return n-low;


    }
};
