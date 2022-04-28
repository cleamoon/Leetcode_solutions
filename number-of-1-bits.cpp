class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t b = 1, ret = 0;
        for(int i = 0; i < 32; i++) {
            if (b & n) {
                ret ++;
            }
            b <<= 1;
        }
        return ret;
    }
};
