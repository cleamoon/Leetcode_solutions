class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        stringstream out;
        string str;
        while (ss >> str) {
            reverse(str.begin(), str.end());
            out << str;
            if (!ss.eof()) {
                out << ' ';
            }
        }
        return out.str();
    }
};
