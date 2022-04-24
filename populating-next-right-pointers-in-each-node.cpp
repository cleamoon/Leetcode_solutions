/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node** start;
    
    int height(Node* root, int h = 1) {
        if (root->left == nullptr)
            return h;
        else 
            return height(root->left, h+1);
    }
    
    void add(Node* root, int target, int h = 1) {
        start[h] = start[h]->next = root->left;
        start[h] = start[h]->next = root->right;
        if (h < target - 1) {
            add(root->left, target, h + 1);
            add(root->right, target, h + 1);
        }
    }
    
    Node* connect(Node* root) {
        if (root == nullptr || root->left == nullptr) return root;
        int h = height(root);    
        start = new Node*[h];
        for (int i = 1; i < h; i++) {
            start[i] = new Node();
        }
        add(root, h);
        return root;
    }
};
