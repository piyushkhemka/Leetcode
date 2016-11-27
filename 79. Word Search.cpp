class Solution {

    int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,1,-1};

    bool recurse(vector<vector<char>>& board, string &word, int i, int j ,const string &myword,
                        int n,vector<vector<int>> &visited) {

        //  cout << myword << " " << i << " " << j << " "  << endl;

        if (myword == word)
            return true;

        if(myword.length() > word.length())
            return false;

        if(myword[myword.length()-1]!=word[myword.length()-1])
            return false;

        visited[i][j] = 1;

        for(int k = 0;k<4;++k) {


            int newx = i + dirx[k];
            int newy = j + diry[k];

            if (newx >=0 && newx < board.size() && newy >=0 && newy < board[0].size() && !visited[newx][newy]) {
                 visited[newx][newy] = 1;
                if (recurse(board,word,newx,newy, myword+board[newx][newy],n+1,visited))
                    return true;
                 visited[newx][newy] = 0;
            }
        }
        return false;
    }



public:
    bool exist(vector<vector<char>>& board, string word) {

        if(board.empty() && word.length() == 0)
            return true;

        else if(board.empty() || word.length() == 0 || word.length() > board.size()*board[0].size())
            return false;

        string cur = "";

        for(int i = 0;i<board.size();++i) {
            for(int j = 0;j<board[0].size();++j) {
                if(board[i][j] == word[0]) {
                    vector<vector<int>> visited(board.size(), vector<int> (board[0].size(),0));
                    if(recurse(board,word,i,j,cur + word[0],0,visited))
                        return true;
                }
            }
        }

        return false;
    }
};
