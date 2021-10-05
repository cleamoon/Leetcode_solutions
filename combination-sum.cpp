/*
	Possible optimizations:
	* Might use backtracking with a stack
*/

class Solution {
public:
    
    int len;
    
    class treeNode {
    public:
        treeNode* parent;
        int value;
        int depth;
        treeNode(treeNode* _parent, int _depth, int _value) : parent(_parent), value(_value), depth(_depth) { }
    };
    
    vector<vector<int>> res; 
    
    void calc(vector<int>& cand, int start, int sum, int target, treeNode* node) {
        if (sum > target) return;
        if (node->depth > 150) return;
        if (start - (int)cand.size() >= 0) return;
        if (sum == target) {
            vector<int> oneres;
            treeNode* temp = node;
            while(temp->parent != temp) {
                oneres.push_back(temp->value);
                temp = temp->parent;
            }
            res.push_back(oneres);
        } else {
            calc(cand, start + 1, sum, target, node);
            treeNode* newNode = new treeNode(node, node->depth+1, cand[start]);
            found2 = calc(cand, start, sum + cand[start], target, newNode);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        treeNode* root = new treeNode(nullptr, 0, 0);
        root->parent = root;
        calc(candidates, 0, 0, target, root);
        return res;
    }
};
