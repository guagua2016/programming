struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){
    }
};


class Solution{
public:
    ListNode* FindKthToTail(ListNode* pListHead,unsigned int k){
        ListNode *p = pListHead;
        ListNode *q = pListHead;
        while(k--){
            if(p){
                p = p->next;
            }else{
                return nullptr;
            }
        }
        while(p){
            p = p->next;
            q = q->next;
        }
        return q;
    }
};