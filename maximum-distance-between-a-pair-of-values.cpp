/*
	Possible speedups:
	* Use loop instead of recursion
	* Do not iterate through the entire nums2. Use found result in num1 to jump forward faster
	* Use class variables to avoid copy values around
*/

class Solution {
public:
    int find(vector<int>& nums, int begin, int end, int value) {
        if (begin >= end) {
            if (nums[begin] <= value)
                return begin;
            else
                return -1;
        } else {
            int mid = (begin + end) / 2;
            if (nums[mid] > value)
                return find(nums, mid+1, end, value);
            else if (nums[mid] < value)
                return find(nums, begin, mid, value);
            else {
                int id = -1;
                id = find(nums, begin, mid, value);
                if (id != -1)
                    return id;
                else
                    return find(nums, mid+1, end, value);
            }
        }
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxdis = 0;
        for (int i = nums2.size()-1; i>=0; i--) {
            int id = find(nums1, 0, min(i, (int)nums1.size()-1), nums2[i]);
            if (id != -1) {
                if (i - id > maxdis) maxdis = i - id;
            }
        }


        return maxdis;
    }
};
