class Solution {
public:
    int find(vector<int>& nums, int target, int begin, int end) {
        if (begin >= end)
            return end;
        if (begin + 1 == end) {
            if (target > nums[begin]) {
                return begin + 1;
            } else if (target <= nums[begin]) {
                return begin;
            }
        }
        int mid = (begin + end) / 2;
        if (nums[mid] > target) {
            return find(nums, target, begin, mid);
        } else if (nums[mid] < target) {
            return find(nums, target, mid + 1, end);
        } else {
            return mid;
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size());
    }
};
