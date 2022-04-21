class Solution {
public:
    int ret;
    bool closed = true;
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 1) {
            return;
        }
        if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) {
            closed = false;
        }
        grid[x][y] = 1;
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    ret ++;
                    dfs(grid, i, j);
                    if (!closed) {
                        ret--;   
                    }
                    closed = true;
                }
            }
        }
        return ret;
    }
};
