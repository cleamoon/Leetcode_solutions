class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        int sum = 1;
        sum += dfs(grid, x - 1, y);
        sum += dfs(grid, x + 1, y);
        sum += dfs(grid, x, y - 1);
        sum += dfs(grid, x, y + 1);
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    int area = dfs(grid, i, j);
                    maxarea = maxarea > area ? maxarea : area;
                }
            }
        }
        return maxarea;
    }

};
