class Solution {
public:
    int findPosisonedDuration(vector<int>& t, int d) {

        if(!d)
            return 0;
        int sum = 0;
        int start = -1;
        int end = -1;
        for(int i = 0; i < t.size();i++) {
            start = t[i]-1;
             if (end >= start)
                start = end;
            end = t[i] + d - 1;
            sum+= (end-start);
        }
        return sum;
    }
};
