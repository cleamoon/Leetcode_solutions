class Solution {
public:
    static bool comp(string s1, string s2) {
        if (s1.length() < s2.length()) return true;
        else if(s1.length() > s2.length()) return false;
        else {
            for (int i = 0; i < s1.length(); i++) {
                if(s1[i] < s2[i]) return true;
                else if (s1[i] > s2[i]) return false;
            }
        }
        return false;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        return nums[nums.size()-k];
    }
};
