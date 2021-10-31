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
    bool res = true;
    
    int height(TreeNode* node) {
        int hl, hr;
        if (node == nullptr) return 0;
        if (node->left  == 0) hl = 0;
        else hl = height(node->left)+1;
        if (node->right == 0) hr = 0;
        else hr = height(node->right)+1;
        if (abs(hl-hr) > 1) 
            res = false;
        return max(hl, hr);
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return res;
    }
};
