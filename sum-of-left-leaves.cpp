class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr) {
            if (root->right == nullptr) {
                if (isLeft) 
                    return root->val;
            }
            return sumOfLeftLeaves(root->right, false);
        } else {
            if (root->right == nullptr) {
                return sumOfLeftLeaves(root->left, true);
            } else {
                return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
            }
        }
        return 0;
    }
};
