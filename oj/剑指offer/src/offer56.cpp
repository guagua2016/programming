struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode* dummy = new ListNode(-1);
        dummy->next = pHead;
        ListNode* p = dummy;
   
        ListNode* q =pHead;
        bool hasDuplicate = false;;
        while(q && q->next){
            if(q->val == q->next->val){
                q = q->next;
                hasDuplicate = true;
            }else{
                if(hasDuplicate){
                    p->next = q->next;
                    q = q->next;
                    hasDuplicate = false;
                }else{
                    p = p->next;
                    q = q->next;
                }
            }
        }
        if(hasDuplicate){
            p->next =q->next;
        }
        return dummy->next;
    }
};