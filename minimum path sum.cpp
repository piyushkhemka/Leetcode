class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > a(m, vector<int> (n));
        
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++){
                a[i][j]  = grid[i][j];
            }
        }
        int top,left;
        for(int i = 0; i<m;i++) {
            for(int j = 0;j<n;j++){
                
                if(i-1<0 && j-1<0)
                    continue;
                
                top = i-1>=0?a[i-1][j]:INT_MAX;
                left = j-1>=0?a[i][j-1]:INT_MAX;
                
                a[i][j] = a[i][j] + min(top,left);
             //   cout << i << " " << j <<endl;
             //   cout << top << " " << left<<" " << a[i][j]<<endl;
            }
        }
        
        // for(int i = 0; i<m;i++) {
        //     for(int j = 0;j<n;j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        
        return a[m-1][n-1];
        
    }
};