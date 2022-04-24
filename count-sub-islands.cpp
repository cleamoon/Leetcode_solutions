class Solution {
public:
    bool isSub = true;
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& base) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }
        if (base[x][y] == 0) 
            isSub = false;
        grid[x][y] = 0;
        dfs(grid, x - 1, y, base);
        dfs(grid, x + 1, y, base);
        dfs(grid, x, y - 1, base);
        dfs(grid, x, y + 1, base);

    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ret = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    dfs(grid2, i, j, grid1);
                    if (isSub) {
                        ret++;   
                    }
                    isSub = true;
                }
            }
        }
        return ret;

    }
};
