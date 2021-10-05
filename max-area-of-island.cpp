class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxSize = 0;

        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j]) {
                    visited[i][j] = true;
                    int size = 0;
                    queue<vector<int>> q;
                    q.push(vector<int>{i, j});
                    while(!q.empty()) {
                        size ++;
                        int x = q.front()[0];
                        int y = q.front()[1];
                        q.pop();
                        if (x != 0 && grid[x-1][y] && !visited[x-1][y]) {
                            q.push(vector<int>{x-1, y});
                            visited[x-1][y] = true;
                        }
                        if (x != grid.size()-1 && grid[x+1][y] && !visited[x+1][y]) {
                            q.push(vector<int>{x+1, y});
                            visited[x+1][y] = true;
                        }
                        if (y != 0 && grid[x][y-1] && !visited[x][y-1]) {
                            q.push(vector<int>{x, y-1});
                            visited[x][y-1] = true;
                        }
                        if (y != grid[0].size()-1 && grid[x][y+1] && !visited[x][y+1]) {
                            q.push(vector<int>{x, y+1});
                            visited[x][y+1] = true;
                        }
                    }
                    if (size > maxSize) {
                        maxSize = size;
                    }
                }
            }
        }
        return maxSize;
    }
};
