class Solution {
public:
    vector<int> res; 
    
    void calc(TreeNode* node) {
        if(node == nullptr) return;
        calc(node->left);
        calc(node->right);
        res.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        calc(root);
        return res;
    }
};
