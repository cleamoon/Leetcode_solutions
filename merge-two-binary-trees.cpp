class Solution {
public:
    void solve(TreeNode* t1, TreeNode* t2) {
        if(t1->left != NULL and t2->left != NULL) {
            solve(t1->left, t2->left);   
        } else {
            if(t1->left == NULL) t1->left = t2->left;
            if(t2->left == NULL) ;
        }
        if(t1->right != NULL and t2->right != NULL) {
            solve(t1->right, t2->right);
        } else {
            if(t1->right == NULL) t1->right = t2->right;
            if(t2->right == NULL) ;
        }
        t1->val += t2->val;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        solve(t1, t2);
        return t1;
    }
};
