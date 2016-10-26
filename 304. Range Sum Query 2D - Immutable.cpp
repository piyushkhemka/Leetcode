class NumMatrix {
private:
    vector<vector<int> > sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i = 0;i<matrix.size();i++){
            sums.push_back(vector<int> ());
            sums[i].push_back(0);
            for(int j = 0;j<matrix[i].size();j++) {
                sums[i].push_back(matrix[i][j]+sums[i].back());
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int res = 0;

        // int rightupper = row2,col1
        // int leftbelow = row1,col2

        for(int i = row1;i<=row2;i++) {
            res = res + sums[i][col2+1] - sums[i][col1];
        }

        return res;
    }
};

// Much smarter solution that brings down the time complexity to O(1)
//
// https://leetcode.com/articles/range-sum-query-2d-immutable/
// Explanation: https://discuss.leetcode.com/topic/29536/clean-c-solution-and-explaination-o-mn-space-with-o-1-time/2

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) return;
        sum = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                sum[i+1][j+1] = matrix[i][j] + sum[i][j+1] + sum[i+1][j] -sum[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] -sum[row1][col2+1] +sum[row1][col1];
    }
private:
    vector<vector<int>> sum;
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
