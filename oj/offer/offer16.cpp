struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};


class Solution
{
public:
    ListNode* Merge(ListNode* pHead1,ListNode* pHead2){
        ListNode* dummy = new ListNode(-1);

        ListNode* d = dummy;
        ListNode* p = pHead1;
        ListNode* q = pHead2;
        while(p && q){
            if(p->val < q->val){
                d->next = p;
                p = p->next;
            }else{
                d->next = q;
                q = q->next;
            }
            d = d->next;
        }
        if(p){
            d->next = p;
        }
        if(q){
            d->next = q;
        }
        return dummy->next;
    }
};