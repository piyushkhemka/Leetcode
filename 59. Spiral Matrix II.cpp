class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int k = 1;
        enum DIR {lefttoright, toptodown, righttoleft, downtoup};

        DIR dir = lefttoright;

        vector<vector<int>> m (n, vector<int> (n));

        if (!n)
            return m;

        while(top<=down && left<=right) {
            if (dir == lefttoright) {
                for(int i = left; i<=right; ++i) {
                    m[top][i] = k;
                    k++;
                }
                dir = toptodown;
                top++;
            }
             else if (dir == toptodown) {

                for(int i = top; i<=down; ++i) {
                    m[i][right] = k;
                    k++;
                }
                dir = righttoleft;
                right--;
            }
             else if (dir == righttoleft) {

                for(int i = right; i>=left; --i) {
                    m[down][i] = k;
                    k++;
                }
                dir = downtoup;
                down--;

            }
             else if (dir == downtoup) {

                for(int i = down; i>=top; --i) {
                    m[i][left] = k;
                    k++;
                }
                dir = lefttoright;
                left++;
            }
        }
        return m;
    }
};
