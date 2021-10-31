class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<vector<pair<int, int>>>> \
            s(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>{}));

        s[0][0].push_back(make_pair(dungeon[0][0], dungeon[0][0]));
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                int cur = dungeon[i][j];
                if (i != 0) {
                    for (auto k = 0; k < s[i-1][j].size(); k++) {
                        int newhp = s[i-1][j][k].first + cur;
                        auto newp = make_pair(newhp, min(newhp, s[i-1][j][k].second));
                        bool ignore = false;
                        for (auto l = 0; l < s[i][j].size(); l++) {
                            if (newp.first < s[i][j][l].first and newp.second < s[i][j][l].second) {
                                ignore = true;
                                break;
                            } else if (newp.first > s[i][j][l].first and newp.second > s[i][j][l].second) {
                                s[i][j][l].first = newp.first;
                                s[i][j][l].second = newp.second;
                                ignore = true;
                                break;
                            }
                        }
                        if (ignore) 
                            continue;
                        s[i][j].push_back(newp);
                    }
                }
                if (j != 0) {
                    for (auto k = 0; k < s[i][j-1].size(); k++) {
                        int newhp = s[i][j-1][k].first + cur;
                        auto newp = make_pair(newhp, min(newhp, s[i][j-1][k].second));
                        bool ignore = false;
                        for (auto l = 0; l < s[i][j].size(); l++) {
                            if (newp.first < s[i][j][l].first and newp.second < s[i][j][l].second) {
                                ignore = true;
                                break;
                            } else if (newp.first > s[i][j][l].first and newp.second > s[i][j][l].second) {
                                s[i][j][l].first = newp.first;
                                s[i][j][l].second = newp.second;
                                ignore = true;
                                break;
                            }
                        }
                        if (ignore) 
                            continue;
                        s[i][j].push_back(newp);
                    }
                }
            }
        }
        int maxhp = INT_MIN;
        for (auto p : s[m-1][n-1]) {
            if (p.second > maxhp)
                maxhp = p.second;
        }
        return 1 - min(0, maxhp);
    }
};
