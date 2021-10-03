/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* add(vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        } else if (begin == end) {
            return new TreeNode(nums[begin]);
        } else {
            int mid = (begin + end) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left  = add(nums, begin, mid-1);
            node->right = add(nums, mid+1, end);
            return node;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return add(nums, 0, nums.size()-1);
    }
};
