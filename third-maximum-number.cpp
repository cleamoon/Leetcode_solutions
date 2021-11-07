class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = INT_MAX;
        int ord = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < max) {
                ord ++;
                if (ord == 3) {
                    return nums[i];
                }
                max = nums[i];
            }
        }
        return nums[nums.size()-1];

    }
};
