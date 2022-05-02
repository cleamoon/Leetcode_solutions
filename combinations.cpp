class Solution {
public:
    vector<vector<int>> ret;
    
    void add(int max, int top) {
        /*for (int i = 0; i < ret.size(); i++) {
            copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout, ", "));
            cout << endl;   
        }*/
        int level = 0;
        if (!ret.empty()) {
            level = ret[0].size();
            if (level == top)
                return;
            vector<vector<int>> newret; 
            for (int i = 0; i < ret.size(); i++) {
                int max_of_level = ret[i][ret[i].size()-1];
                for (int j = max_of_level + 1; j <= max - (top - level) + 1; j++) {
                    vector<int> base = ret[i];
                    base.push_back(j);
                    newret.push_back(base);
                }
            }
            ret = newret; 
        } else {
            for (int i = 0; i <= max - top; i++) {
                ret.push_back(vector<int>(1, i + 1));
            }
        }
        add(max, top);
    }
    
    vector<vector<int>> combine(int n, int k) {
        add(n, k);
        return ret; 
    }
};
