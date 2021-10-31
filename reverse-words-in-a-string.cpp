class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        stringstream ss;
        ss << s;
        string tmp;
        while(ss >> tmp) {
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        stringstream anss;
        for(int i = 0; i < res.size(); i++) {
            if (i == res.size() - 1) {
                anss << res[i];
            } else {
                anss << res[i] << ' ';
            }
        }
        return anss.str();
    }
};
