/*
    Heap algorithms inserting to a set
    Possible improvement: 
    * Check possible duplicate before recursion (tried, somehow didn't worked)
    * Generate results direct without using a set
*/

class Solution {
public:
    set<vector<int>> ans = {};
    
    void heap(vector<int>& nums, int k) {
        if (k == 0) {
            ans.insert(nums);
        } else {
            heap(nums, k - 1);
            for (int i = 0; i < k; i++) {
                if (k % 2) {
                    swap(nums[k], nums[i]);
                } else{
                    swap(nums[k], nums[0]);
                }
                heap(nums, k - 1);
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        heap(nums, nums.size()-1);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
