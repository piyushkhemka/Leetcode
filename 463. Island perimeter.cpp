class Solution {
public:


    int islandPerimeter(vector<vector<int>>& grid) {

        int tot = 0;
        int minus = 0;
        int n = grid.size();
        int m = grid[0].size();

        int dirx[4] = {-1,0,1,0};
        int diry[4] = {0,1,0,-1};
        for(int i = 0;i<grid.size();++i) {
            for(int j = 0;j<grid[i].size();++j) {

                if (grid[i][j] == 1) {

                    tot++;

                    for(int k = 0;k<4;k++) {
                        int newx = i + dirx[k];
                        int newy = j + diry[k];

                        if(newx>=0 && newx<n && newy >=0 && newy<m && grid[newx][newy] == 1)
                            minus++;
                    }

                }

            }
        }
        return (tot*4-minus);
    }
};
