// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int find(int b, int e) {
        if (b  == e) {
            if (isBadVersion(b))
                return b;
            else 
                return b - 1;
        }
        int mid = b / 2 + e / 2 + (b & e) % 2;
        if (isBadVersion(mid)) {
            return find(b, mid);
        } else {
            return find(mid + 1, e);
        }
        
    }
    
    int firstBadVersion(int n) {
        return find(1, n);
    }
};
