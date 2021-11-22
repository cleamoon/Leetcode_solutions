class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int b = 1, t = 0;
            while (b <= i) {
                if (i & b) {
                    t ++;
                }
                b *= 2;
            }
            ans.push_back(t);
        }
        return ans;
    }
};
