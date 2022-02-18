class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0), * moreHead = new ListNode(0);
        ListNode* lessTail = lessHead, * moreTail = moreHead;
        while (head != nullptr) {
            if (head->val < x) {
                lessTail = lessTail->next = new ListNode(head->val);
            } else {
                moreTail = moreTail->next = new ListNode(head->val);
            }
            head = head->next;
        }
        if (lessHead->next != nullptr) {
            lessTail->next = moreHead->next;
            return lessHead->next;
        } else {
            return moreHead->next;
        }
    }
};
