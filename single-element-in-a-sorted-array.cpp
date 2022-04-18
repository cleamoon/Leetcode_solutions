class Solution {
public:
    int calc(vector<int>& nums, int begin, int end) {
        int mid = (begin + end) / 2;
        if (mid == nums.size() - 1 || mid == 0) {
            return nums[mid];
        }
        if (mid % 2 == 1) {
            mid --;
        }
        if (nums[mid] == nums[mid+1]) {
            return calc(nums, mid+1, end);
        }
        if (mid == 0) {
            return nums[0];
        }
        if (nums[mid] != nums[mid-1]) {
            return nums[mid];
        } else {
            return calc(nums, begin, mid);
        }
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return calc(nums, 0, nums.size());
    }
};
