class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(-1, head);
        ListNode* pre = &dummy;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q) {
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
            q = p->next;
        }
        return pre->next;
    }
};