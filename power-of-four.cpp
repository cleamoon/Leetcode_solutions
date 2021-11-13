class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 0) return false;
        long b = 1;
        for(int i = 0; i < 16; i++) {
            if (b == n) return true;
            b *= 4;
        }
        return false;
    }
};
