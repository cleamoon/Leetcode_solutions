class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    if (i == 0) perimeter ++;
                    else if (!grid[i-1][j]) perimeter ++;
                    if (i == grid.size()-1) perimeter ++;
                    else if (!grid[i+1][j]) perimeter ++;
                    if (j == 0) perimeter ++;
                    else if (!grid[i][j-1]) perimeter ++;
                    if (j == grid[0].size()-1) perimeter ++;
                    else if (!grid[i][j+1]) perimeter ++;
                }
            }
        }
        return perimeter;
    }
};
