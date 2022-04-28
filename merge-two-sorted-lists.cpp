class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(true) {
            if (list1 == nullptr) {
                curr->next = list2;
                break;
            }
            if (list2 == nullptr) {
                curr->next = list1;
                break;
            }
            if (list1->val < list2->val) {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        return head->next;
    }
};
