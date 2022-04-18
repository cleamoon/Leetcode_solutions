class Solution {
public:
    int binSrch(vector<int>& nums, int begin, int end, int trg) {
        if (begin >= end) {
                return -1;
        } 
        int mid = (begin + end)/2;
        if (trg < nums[mid]) {
            return binSrch(nums, begin, mid, trg);
        } else if (trg > nums[mid]) {
            return binSrch(nums, mid + 1, end, trg);
        } else {
            return mid;
        }
    }
    
    int search(vector<int>& nums, int target) {
        return binSrch(nums, 0, nums.size(), target);
    }
};
