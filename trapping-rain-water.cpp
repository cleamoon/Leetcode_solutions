class Solution {
public:
    int trap(vector<int>& height) {
        int head = 0, tail = height.size()-1;
        int res = 0;
        int prev = 0;
        while (head < tail) {
            int h = height[head];
            int t = height[tail];
            if (h <= prev) {
                res -= h;
                head++;
                continue;
            } 
            if (t <= prev) {
                res -= t;
                tail--;
                continue;
            }
            int cur = min(h, t);
            if (cur > prev) {
                res += (cur - prev) * (tail - head - 1) - prev;
                prev = cur;
            }
            if (h > t) tail--;
            else head++;
        }
        return res;
    }
};
