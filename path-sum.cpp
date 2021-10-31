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
    bool calc(TreeNode* node, int targetSum, int sum = 0, bool res = false) {
        if (res) return res;
        if (node == nullptr) return res;
        else {
            if (node->left == nullptr and node->right == nullptr) {
                res = (targetSum == sum + node->val);
                return res;
            } else {
                res = calc(node->left, targetSum, sum+node->val, res) or calc(node->right, targetSum, sum+node->val, res);
                return res;
            }
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return calc(root, targetSum);
    }
};
