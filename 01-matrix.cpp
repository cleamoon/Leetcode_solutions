class Solution {
public:
    queue<pair<int, int>> q;
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        auto ret = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ret[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            mat[x][y] = 0;
            if (x > 0 && mat[x-1][y]) {
                ret[x-1][y] = min(ret[x-1][y], ret[x][y] +1);
                q.push(make_pair(x-1, y));
            }
            if (x < m-1 && mat[x+1][y]) {
                ret[x+1][y] = min(ret[x+1][y], ret[x][y] +1);
                q.push(make_pair(x+1, y));
            }
            if (y > 0 && mat[x][y-1]) {
                ret[x][y-1] = min(ret[x][y-1], ret[x][y] +1);
                q.push(make_pair(x, y-1));
            }
            if (y < n-1 && mat[x][y+1]) {
                ret[x][y+1] = min(ret[x][y+1], ret[x][y] +1);
                q.push(make_pair(x, y+1));
            }
        }
        return ret;
    }
};
