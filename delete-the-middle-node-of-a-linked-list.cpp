/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = new ListNode(0);
        slow->next = head;
        ListNode *fast = head;
        if (fast->next == nullptr) return nullptr;
        while(true) {
            fast = fast->next;
            if (fast == nullptr) {
                slow->next = slow->next->next;
                break;
            }
            fast = fast->next;
            if (fast == nullptr) {
                slow->next->next = slow->next->next->next;
                break;
            }
            slow = slow->next;
        }
        return head;
    }
};
