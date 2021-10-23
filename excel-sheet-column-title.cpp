class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> res; 
        while(columnNumber != 0) {
            int rem = columnNumber % 26;
            if (rem == 0) {
                rem = 26;
                columnNumber --;
            }
            res.push_back(rem - 1 + 'A');
            columnNumber /= 26; 
        }
        reverse(res.begin(), res.end());
        return string(res.begin(), res.end());
    }
};
