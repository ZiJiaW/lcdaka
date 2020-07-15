class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto fast = head, slow = head;
        while (slow->next && slow->next->next) {
            fast = fast->next;
            slow = slow->next->next;
        }
        auto mid = fast->next;
        fast->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(mid);
        ListNode pre(-1);
        ListNode* cur = &pre;
        while (left && right) {
            if (left->val <= right->val) {
                cur->next = left;
                cur = left;
                left = left->next;
                cur->next = nullptr;
            } else {
                cur->next = right;
                cur = right;
                right = right->next;
                cur->next = nullptr;
            }
        }
        if (left) cur->next = left;
        else if (right) cur->next = right;
        return pre.next;
    }
};