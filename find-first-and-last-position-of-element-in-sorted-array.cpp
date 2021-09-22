/*
	Possible improvement:
	* Find both of the start and the end in one recursion instead of two
*/

class Solution {
public:
    int find(vector<int>& nums, int target, bool bigger, int start, int end) {
        if (start >= end) {
            if (bigger) {
                if 
                    (        
                        nums[start] == target and \
                        (start == nums.size()-1 or nums[start+1] > target)
                    ) 
                {
                    return start;   
                } else if (start > 0 and nums[start-1] == target) {
                    return start - 1;
                } else {
                    return -1;
                }
            } else {
                if 
                    (
                        nums[start] == target and \
                        (start == 0 or nums[start-1] < target)
                    )
                {
                    return start;
                } else {
                    return -1;
                }
            }
        } else {
            if (bigger) {
                int mid = (start + end) / 2;
                if (nums[mid] <= target) {
                    return find(nums, target, bigger, mid+1, end);
                } else if (nums[mid] > target) {
                    return find(nums, target, bigger, start, mid);
                } 
            } else {
                int mid = (start + end) / 2;
                if (nums[mid] < target) {
                    return find(nums, target, bigger, mid+1, end);
                } else if (nums[mid] >= target) {
                    return find(nums, target, bigger, start, mid);
                } 
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int>{-1,-1};
        }
        int begin = find(nums, target, false, 0, nums.size()-1);
        int end   = find(nums, target, true , 0, nums.size()-1);
        return vector<int>{begin, end};
    }
};
