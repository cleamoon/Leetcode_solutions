class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string>> m;
        
        for (auto s : strs) {
            vector<char> vc(s.begin(), s.end());
            sort(vc.begin(), vc.end());
            auto it = m.find(vc);
            if (it != m.end()) {
                it->second.push_back(s);
            } else {
                m.insert(make_pair(vc, vector<string>{s}));
            }
        }
        
        vector<vector<string>> res;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};
