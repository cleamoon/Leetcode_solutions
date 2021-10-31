class Solution {
public:
    vector<int> res; 
    
    void calc(TreeNode* node) {
        if(node == nullptr) return;
        res.push_back(node->val);
        calc(node->left);
        calc(node->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        calc(root);
        return res;
    }
};
