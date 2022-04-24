class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <  1) return 0;
        if (s.length() == 1) return 1;
        unordered_set <char> a;
        int i, j, ans;
        i = j = ans = 0;
        while(i < s.length() && j < s.length()) {
            if (a.find(s[j]) == a.end()) {
                a.insert(s[j]); 
                ans = ans < a.size() ? a.size() : ans;
                j++;
            } else {
                a.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
