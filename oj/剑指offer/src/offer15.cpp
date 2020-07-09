
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
    
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        ListNode* p = pHead->next;
        ListNode* q = pHead;
        q->next = nullptr;
        
        while(p->next){
            ListNode* pNext = p->next;
            p->next = q;
            q = p;
            p = pNext;
        }
        p->next = q;
        return p;

    }
};