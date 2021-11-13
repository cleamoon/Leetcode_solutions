class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n); 
        while(true) {
            int sum = 0;
            while(n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (sum == 1)
                return true;
            auto it = s.find(sum);
            if (it != s.end())
                break;
            else 
                s.insert(sum);
        }
        return false;
    }
};
