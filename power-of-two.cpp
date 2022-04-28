class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return (int)(n & (n-1)) == 0;
    }
};
