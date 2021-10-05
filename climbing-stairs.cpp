class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int t;
        for (int i = 1; i < n; i++) {
            t = a + b;
            a = b;
            b = t;
        }
        return b;
    }
};
