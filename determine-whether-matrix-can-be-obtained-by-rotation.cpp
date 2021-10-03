class Solution {
public:
    bool equal(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        for (int i = 0; i < m1.size(); i++) {
            for (int j = 0; j < m2.size(); j++) {
                if (m1[i][j] != m2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void rot(vector<vector<int>>& matrix) {
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
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (equal(mat, target)) return true;
        rot(mat);
        if (equal(mat, target)) return true;
        rot(mat);
        if (equal(mat, target)) return true;
        rot(mat);
        if (equal(mat, target)) return true;
        return false;
    }
};
