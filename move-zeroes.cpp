class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int vanc = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[vanc + 1] = nums[i];
                vanc ++;
            }
        }
        for(int i = vanc + 1; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
