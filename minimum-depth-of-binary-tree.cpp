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
    int minDepth(TreeNode* root, int depth = 0) {
        if (root == nullptr) {
            return depth;
        } else if (root->left == nullptr) {
            if (root->right == nullptr) return depth + 1;
            return minDepth(root->right, depth + 1);
        } else if (root->right == nullptr) {
            return minDepth(root->left,  depth + 1);
        } else {
            int ml = minDepth(root->left , depth + 1);
            int mr = minDepth(root->right, depth + 1);
            return min(ml, mr);
        }
    }
};
