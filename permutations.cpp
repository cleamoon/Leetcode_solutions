/*
    Heap algorithms
*/

class Solution {
public:
    vector<vector<int>> ans = {};
    
    void heap(vector<int>& nums, int k) {
        if (k == 0) {
            ans.push_back(nums);
        } else {
            heap(nums, k - 1);
            for (int i = 0; i < k; i++) {
                if (k % 2) {
                    swap(nums[k], nums[i]);
                } else {
                    swap(nums[k], nums[0]);
                }
                heap(nums, k - 1);
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        heap(nums, nums.size()-1);
        return ans;
    }
};
