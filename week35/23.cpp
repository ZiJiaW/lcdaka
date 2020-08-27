ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode prehead(-1);
    ListNode *p = &prehead;
    while(l1 != NULL || l2 != NULL)
    {
        if(l1 == NULL || l2 == NULL)
        {
            p->next = l1==NULL ? l2 : l1;
            l2 = l1 = NULL;
        }
        else if(l1->val < l2->val)
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
    }
    return prehead.next;
}
ListNode* Merge(vector<ListNode*>& lists, int a, int b)
{
    ListNode* A;
    ListNode* B;
    if(a == b)
        return lists[a];
    A = Merge(lists, a, (a+b)/2);
    B = Merge(lists, (a+b)/2+1, b);
    return mergeTwoLists(A, B);
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k;
        k = lists.size();
        if(k == 0)
            return NULL;
        return Merge(lists, 0, k-1);
    }
};