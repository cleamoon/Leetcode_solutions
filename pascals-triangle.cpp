class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> fstr = {1};
        res.push_back(fstr);
        for(int i = 0; i < numRows-1; i++) {
            vector<int> row = {1};
            for(int j = 0; j < res[i].size()-1; j++) {
                row.push_back(res[i][j] + res[i][j+1]);
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;    
    }
};
