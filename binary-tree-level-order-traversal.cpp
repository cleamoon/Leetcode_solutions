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
/*
	Possible improvement:
	* No need for a separate vector row. The previous q should work.
	* q can be replaced by a c array
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> nq;
            vector<int> row;
            while(!q.empty()) {
                TreeNode* n = q.front();
                q.pop();
                row.push_back(n->val);
                if (n->left != nullptr)
                    nq.push(n->left);
                if (n->right != nullptr)
                    nq.push(n->right);
            }
            if (!row.empty()) {
                res.push_back(row);                
            }
            if (!nq.empty()) {
                q = nq;
            }
        }
        return res;
    }
};
