class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (auto num : nums) {
            if (num < 0) {
                neg.push_back(num*num);
            } else {
                pos.push_back(num*num);
            }
        }
        if (neg.empty()) {
            return pos;
        }
        reverse(neg.begin(), neg.end());
        if (pos.empty()) {
            return neg;
        }
        vector<int> ret;
        int itp = 0, itn = 0;
        while(true) {
            if (pos[itp] > neg[itn]) {
                ret.push_back(neg[itn]);
                itn++;
            } else {
                ret.push_back(pos[itp]);
                itp++;
            }
            if (itp == pos.size()) {
                for (int i = itn; i < neg.size(); i++) {
                    ret.push_back(neg[i]);
                }
                break;
            }
            if (itn == neg.size()) {
                for (int i = itp; i < pos.size(); i++) {
                    ret.push_back(pos[i]);
                }
                break;
            }
        }
        return ret;
    }
};
