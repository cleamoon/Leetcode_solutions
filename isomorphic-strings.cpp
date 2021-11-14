class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s2t;
        map<char, char> t2s;
        
        for(int i = 0; i < s.length(); i++) {
            auto it = s2t.find(s[i]);
            auto jt = t2s.find(t[i]);
            if (it != s2t.end() and it->second != t[i]) return false;
            else s2t.insert(make_pair(s[i], t[i]));
            if (jt != t2s.end() and jt->second != s[i]) return false;
            else t2s.insert(make_pair(t[i], s[i]));
        }
        return true;
    }
};
