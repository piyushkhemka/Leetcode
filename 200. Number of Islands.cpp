class Solution {

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {

        int xdir[4] = {-1,1,0,0};
        int ydir[4] = {0,0,-1,1};

        visited[i][j] = 1;

        for(int k = 0;k<4;++k) {
            int x = i + xdir[k];
            int y = j + ydir[k];

            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && !visited[x][y] && grid[x][y] == '1')
                dfs(x,y,grid,visited);
        }
    }



public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        if(grid.empty())
            return count;

        vector<vector<int> > visited(grid.size(), vector<int> (grid[0].size(), 0));

        for(int i = 0;i< grid.size(); ++i) {
            for(int j = 0;j<grid[0].size();++j) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    ++count;
                    dfs(i,j,grid,visited);
                }
            }
        }

        for(int i = 0;i< grid.size(); ++i) {
            for(int j = 0;j<grid[0].size();++j) {
                cout << visited[i][j] << " ";
                }
            cout << endl;
            }

        return count;


    }
};
