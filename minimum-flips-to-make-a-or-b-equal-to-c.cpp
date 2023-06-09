class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        int upper = max(max(a, b), c);

        for (int base = 1; base <= upper; base *= 2) {
            if ((c & base) != 0) {
                if ((a & base) == 0 && (b & base) == 0) {
                    ans++;
                }
            } else {
                if ((a & base) != 0) {
                    ans++;
                }
                if ((b & base) != 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};