class Solution {
public:
    
    int length(long in, int ans = 1) {
        if (in == 0) return ans;
        else return length(in >> 1, ans + 1);
    }
    
    int divide(int did, int dis) {
        long dividend = did;
        long divisor = dis;
        bool neg = false;
        if (dividend < 0) {
            if (divisor > 0) {
                neg = true;
            } else {
                divisor = -divisor;
            }
            dividend = -dividend;
        } else if (divisor < 0) {
            neg = true;
            divisor = -divisor;
        }
        int ans = 0;
        while(true) {
            if (divisor > dividend) break;
            int p = length(dividend) - length(divisor);
            if (p > 0) {
                if ((divisor << p) > dividend) 
                    p--;
            } else if (p < 0) {
                break;
            }
            ans += 1<<p;
            dividend -= divisor << p;
        }
        if (ans == -2147483648)
            if (!neg)
                return 2147483647;
            else 
                return -2147483648;
        if (neg) {
            return -ans;
        } else
            return ans;
        
    }
};
