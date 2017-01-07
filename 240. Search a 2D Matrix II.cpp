class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty() || matrix[0].empty())
            return false;


        int row = 0;
        int col = matrix[0].size()-1;


        while(col >=0 && row < matrix.size()) {

            if(matrix[row][col] == target)
                return true;

            else if (matrix[row][col] > target)
                col--;

            else
                row++;

        }
        return false;

    }
};

-------


// Divide & conquer

class Solution {

    bool helper(vector<vector<int>>& matrix, int target, int rlow, int rhigh, int clow, int chigh) {
        if ((rlow > rhigh) || (clow > chigh))
            return false;

        int rmid = rlow + (rhigh-rlow)/2;

        int cmid = clow + (chigh-clow)/2;

        if (matrix[rmid][cmid] == target)
            return true;

        else if  (matrix[rmid][cmid] > target)
            return helper(matrix, target, rlow, rhigh, clow, cmid - 1)
            || helper(matrix, target, rlow, rmid-1, cmid, chigh);

        else
            return helper(matrix, target, rmid+1, rhigh, clow, chigh)
            || helper(matrix, target, rlow, rmid, cmid+1, chigh);
    }


public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        int rlow = 0;
        int clow = 0;
        int chigh = matrix[0].size()-1;
        int rhigh = matrix.size()-1;

        return helper(matrix, target, rlow, rhigh, clow, chigh);


    }
};
