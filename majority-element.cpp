class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ord = 0;
        int pre = 0;
        for(auto i : nums) {
            if (ord == 0) {
                pre = i;
            }
            if (i == pre) {
                ord++;
            } else {
                ord--;
            }
        }
        return pre;
    }
};
