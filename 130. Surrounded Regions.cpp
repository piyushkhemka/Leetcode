class Solution {


   int x[4] = {-1,1,0,0};
   int y[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& board, int i , int j) {

        board[i][j] = '?';

        int n = board.size();
        int m = board[0].size();


        for(int k = 0;k < 4; ++k) {

            int newx = i+x[k];
            int newy = j+y[k];

            if (newx > 0 && newy > 0 && (newx < n-1) && (newy < m-1) && board[newx][newy] == 'O')
                dfs(board,newx,newy);

        }

    }
public:
    void solve(vector<vector<char>>& board) {

        if (board.empty())
            return;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<n;++i) {
            if(board[i][0] == 'O')
                dfs(board, i,0);

            if(board[i][m-1] == 'O')
                dfs(board, i,m-1);

        }

        for(int j = 1;j<m-1;++j){
            if(board[0][j] == 'O')
                dfs(board, 0,j);

            if(board[n-1][j] == 'O')
                dfs(board, n-1,j);
        }

        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j) {
                if(board[i][j] == '?')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }


        return;


    }
};
