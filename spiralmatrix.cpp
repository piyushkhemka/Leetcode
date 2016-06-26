class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
    vector<int> result;
    
    if(A.size()<1)
        return result;
        
    enum Dir {up,down,left,right};
    
    int top = 0;
    int bottom = A.size()-1;
    int rightmost = A[0].size()-1;
    int leftmost = 0;
    
    Dir curdir = right;
    int i;
    while(top <=bottom && leftmost<=rightmost) {
        if(curdir == right) {
            for(i = leftmost;i<=rightmost;i++) 
                result.push_back(A[top][i]);
            top++;
            curdir = down;
        }
        else if(curdir == down) {
            for(i = top;i<=bottom;i++)
                result.push_back(A[i][rightmost]);
            rightmost--;
            curdir = left;
        }
        else if(curdir == left) {
            for(i = rightmost ;i>=leftmost;i--)
                result.push_back(A[bottom][i]);
            bottom--;
            curdir = up;
        }
        else  { //up
            for(i = bottom;i>=top;i--)
                result.push_back(A[i][leftmost]);
            leftmost++;
            curdir = right;
        }
    }
    
    return result;
    
    
    }
};