class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < 0) {
                min -= nums[i];
            } else {
                if (min - nums[i] > 1) {
                    min -= nums[i];
                } else {
                    min = 1;
                }
            }
        }
        return min;
    }
};
