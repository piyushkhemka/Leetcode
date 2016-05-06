class Solution {
public:
    int maxSubArray(vector<int>& a) {
        if(a.empty()) return INT_MIN;
        int sum = 0;
        int maxsum = INT_MIN;
        int n = a.size();
        bool flag = false;
        for(int i = 0; i<n; i++ )
        {
            if(a[i] >=0) {
                flag = true;
                break;
            }
            maxsum = max(maxsum,a[i]);
            
        }
        if(!flag)
            return maxsum;
            
        maxsum = INT_MIN;
            
        for(int i = 0;i<n;i++) {
            if(sum+a[i] < 0 ) {
                sum = 0;
            }
            else {
            sum = sum + a[i];
            }
            maxsum = max(sum,maxsum);
        }
        return maxsum;
    }
};