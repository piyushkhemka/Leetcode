class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        if (board.empty())
            return;

        int row = board.size();
        int col = board[0].size();

        int xdir[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int ydir[8] = {-1, -1,-1, 0, 0, 1, 1,  1};

        for(int i = 0; i<row; ++i) {
            for(int j =0; j<col;++j) {

                int sum = 0;

                for(int k = 0; k<8; ++k) {

                    int x = i+xdir[k];
                    int y = j+ydir[k];

                    if(x>=0 && x<row && y>=0 && y<col) {
                        if (board[x][y] > 0)
                            sum++;
                    }

                }

                if (board[i][j] <= 0)
                    sum = -1*sum;

                if (board[i][j] && sum == 0)
                // in case sum is 0 and current value is 1, retain it in
                // order to not mess up neighbour count of other cells that come after it.
                    board[i][j] = 1;

                else
                    board[i][j] = sum;

            }
        }

        // for(int i = 0; i<row; ++i) {
        //     for(int j=0 ;j<col;++j) {

        //         cout << board[i][j] << " ";
        //     }

        //     cout << endl;

        // }


        for(int i = 0; i<row; ++i) {
            for(int j=0 ;j<col;++j) {
                
                if (board[i][j] == -3)
                    board[i][j] = 1;

                else if (board[i][j] >=2 && board[i][j] <=3)
                    board[i][j] = 1;

                else if (board[i][j] < 2)
                    board[i][j] = 0;

                else if (board[i][j] > 3)
                    board[i][j] = 0;

            }

        }

        return;

    }
};
