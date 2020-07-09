struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};


class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2){
        ListNode* p = pHead1;
        ListNode* q = pHead2;

        while(q && p){
            p=p->next;
            q=q->next;
        }

        int n=0;
        if(p){
            while(p){
                p = p->next;
                n++;
            }
            p = pHead1;
            while(n>0){
                p = p->next;
                n--;
            }
      
        }else{
            p = pHead1;
        }

        if(q){
            while(q){
                q = q->next;
                n++;
            }
            q = pHead2;
            while(n>0){
                q=q->next;
                n--;
            }
        }else{
            q = pHead2;
        }

        while(p!=q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};