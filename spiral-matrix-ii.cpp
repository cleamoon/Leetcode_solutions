class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r = 0, c = 0;

        int dir = 0;

        vector<vector<int>> ans(n, std::vector<int>(n, 0));

        for (int i = 1; i <= n * n; i++) {
            ans[r][c] = i;
            switch(dir) {
                case 0:
                    if (c == n - 1 || ans[r][c+1] != 0) {
                        dir++;
                        r++;
                    } else {
                        c++;
                    }
                    break;
                case 1:
                    if (r == n - 1 || ans[r+1][c] != 0) {
                        dir++;
                        c--;
                    } else {
                        r++;
                    }
                    break;
                case 2:
                    if (c == 0 || ans[r][c-1] != 0) {
                        dir++;
                        r--;
                    } else {
                        c--;
                    }
                    break;
                case 3:
                    if (r == 0 || ans[r-1][c] != 0) {
                        dir = 0;
                        c++;
                    } else {
                        r--;
                    }
                    break;
                default:
                    break;
            }
        }

        return ans;
    }
};