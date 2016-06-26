class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {
         int n = A.size();
    if(n < 1)
        return "";
        
    if(n == 1)
        return A[0];
    
    int j;
    string result = "";
    
    int x;
    int mina = INT_MAX;
    
    for(int i = 0;i<n;i++) {
         x = A[i].size();
         mina = min(mina, x);
    }
    
    for(int i = 0;i<mina;i++){ 
        for( j = 1;j<n;j++) {
            if(A[j-1][i]!=A[j][i])
            return result;
        }
        result+=A[j-1][i];
    }
    
    return result;
    }
};