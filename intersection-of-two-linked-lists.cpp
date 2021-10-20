class Solution {
public:
    int length(ListNode* node, int ans = 0) {
        if (node == nullptr) return ans;
        else return length(node->next, ans+1);
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        if (l1 > l2) {
            for (int i = 0; i < l1 - l2; i++) {
                headA = headA -> next;
            }
        } else if (l2 > l1) {
            for (int i = 0; i < l2 - l1; i++) {
                headB = headB -> next;
            }
        }
        while(headA && headB) {
            if (headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
};
