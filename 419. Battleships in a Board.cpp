class Solution {
public:

    void dfs(int i, int j, vector<vector<char> >&board, vector<vector<int> >&visited) {

        visited[i][j] = 1;

        int xdir[] = {-1,0,0,1};
        int ydir[] = {0,1,-1,0};

        for(int m = 0;m<4;m++) {
            int x = i+xdir[m];
            int y = j+ydir[m];

            if (x >= 0 && y >= 0 && x<board.size() && y<board[0].size() && board[x][y] == 'X' && !visited[x][y])
                dfs(x,y,board,visited);

        }      
    }
    int countBattleships(vector<vector<char>>& board) {

        int counter = 0;
        vector<vector<int> > visited(board.size(), vector<int> (board[0].size(), 0));

        for (int i = 0;i<board.size();++i)
            for(int j = 0;j<board[i].size();++j) {

                if (board[i][j] == 'X' && !visited[i][j]) {
                    dfs(i,j,board,visited);
                    counter++;
                }

            }

            return counter;


    }
};
