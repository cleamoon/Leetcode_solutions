class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next = nullptr, *prev = nullptr;
        if (head == nullptr) return nullptr;
        while(head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
