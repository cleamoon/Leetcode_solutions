class Solution {
public:
    bool boundary = false;
    
    int getLand(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 ) {
            return 0;
        }
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) {
            boundary = true;
        }
        int area = 1;
        grid[x][y] = 0;
        area += getLand(grid, x - 1, y);
        area += getLand(grid, x + 1, y);
        area += getLand(grid, x, y - 1);
        area += getLand(grid, x, y + 1);
        return area;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    int area = getLand(grid, i, j);
                    if (!boundary) {
                        ans += area;
                    }
                    boundary = false;
                }
            }
        }
        return ans;
    }
};
