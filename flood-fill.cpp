class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ret = image;
        vector<vector<bool>> visited;
        for (int i = 0; i < image.size(); i++) {
            visited.push_back(vector<bool>(image[0].size(), false));
        }
        int color = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        visited[sr][sc] = true;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ret[x][y] = newColor;
            if (x > 0) {
                if (image[x - 1][y] == color and !visited[x - 1][y]) {
                    q.push(make_pair(x - 1, y));
                    visited[x - 1][y] = true;
                }
            }
            if (x < image.size() - 1) {
                if (image[x + 1][y] == color and !visited[x + 1][y]) {
                    q.push(make_pair(x + 1, y));
                    visited[x + 1][y] = true;
                }
            }
            if (y > 0) {
                if (image[x][y - 1] == color and !visited[x][y - 1]) {
                    q.push(make_pair(x, y - 1));
                    visited[x][y - 1] = true;
                }    
            }
            if (y < image[0].size() - 1) {
                if (image[x][y + 1] == color and !visited[x][y + 1]) {
                    q.push(make_pair(x, y + 1));
                    visited[x][y + 1] = true;
                }
            }
        }
        return ret;
    }
};
