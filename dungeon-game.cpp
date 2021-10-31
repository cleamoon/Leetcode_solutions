class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> s(m, vector<int>(n, INT_MAX));
        m--;
        n--;
        s[m][n] = max(1, 1 - dungeon[m][n]);
        for (auto i = m-1; i >= 0; i--) 
            s[i][n] = min(s[i][n], max(1, s[i+1][n] - dungeon[i][n]));
        for (auto j = n-1; j >= 0; j--) 
            s[m][j] = min(s[m][j], max(1, s[m][j+1] - dungeon[m][j]));
        for (auto i = m-1; i >= 0; i--) {
            for (auto j = n-1; j >= 0; j--) {
                s[i][j] = min(s[i][j], max(1, s[i+1][j] - dungeon[i][j]));
                s[i][j] = min(s[i][j], max(1, s[i][j+1] - dungeon[i][j]));
            }
        }
        return s[0][0];
    }
};
