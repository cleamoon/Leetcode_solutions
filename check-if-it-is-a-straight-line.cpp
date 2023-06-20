class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int u = coordinates[1][1] - coordinates[0][1], d = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); i++) {
            if (d * (coordinates[i][1] - coordinates[0][1]) != u * (coordinates[i][0] - coordinates[0][0])) {
                return false;
            }
        }

        return true;
    }
};
