class Solution {
public:
    // (i, j) -> (j, n-i)
    // (i, j) <- (n-j, i)
    
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size();
        for (int i = 0; i < l / 2 + l % 2; i++) {
            for (int j = 0; j < l / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[l-j-1][i]; 
                matrix[l-j-1][i] = matrix[l-i-1][l-j-1];
                matrix[l-i-1][l-j-1] = matrix[j][l-i-1];
                matrix[j][l-i-1] = tmp;
            }
        }
    }
};
