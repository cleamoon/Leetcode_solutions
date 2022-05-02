class Solution {
public:
    int m, n;
    bool never = false;
    
    inline bool isAllRotted(vector<vector<int>>& grid) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return false;
            }
        }
        return true;
    }
    
    inline void rott(vector<vector<int>>& grid) {
        vector<pair<int, int>> change;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    if (i > 0 and grid[i-1][j] == 1) {
                        change.push_back(make_pair(i-1, j));
                    }
                    if (j > 0 and grid[i][j-1] == 1) {
                        change.push_back(make_pair(i, j-1));
                    }
                    if (i < m-1 and grid[i+1][j] == 1) {
                        change.push_back(make_pair(i+1, j));
                    }
                    if (j < n-1 and grid[i][j+1] == 1) {
                        change.push_back(make_pair(i, j+1));
                    }
                }
            }
        }
        if (change.empty()) {
            never = true;
        }
        for(auto p : change) {
            grid[p.first][p.second] = 2;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        while(true) {
            if (isAllRotted(grid)) {
                return ret;
            }
            if (never) {
                return -1;
            }
            rott(grid);
            ret++;
        }
        return ret;
    }
};
