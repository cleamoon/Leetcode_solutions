class Solution {
public:
    vector<int> res;

    void travel(TreeNode* node) {
        if (node == nullptr) return;
        travel(node->left);
        res.push_back(node->val);
        travel(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        travel(root);
        return res;
    }
};
