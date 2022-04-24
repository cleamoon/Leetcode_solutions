class Solution {
public:
    inline bool equal(int* m1, int* m2) {
        for (int i = 0; i < 26; i++) {
            if (m1[i] != m2[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int m1[26];
        int m2[26];
        memset(m1, 0, 26 * sizeof(int));
        memset(m2, 0, 26 * sizeof(int));

        int l = s1.length();
        int i = 0;
        for (; i < l; i++) {
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        while(true) {
            if (equal(m1, m2)) {
                return true;
            }
            if (i == s2.length()) {
                break;
            }
            m2[s2[i  ]-'a']++;
            m2[s2[i-l]-'a']--;
            i++;
        }
        return false;
    }
};
