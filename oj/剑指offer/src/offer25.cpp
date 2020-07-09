struct RandomListNode{
    int label;
    struct RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};


class Solution
{
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == nullptr) return nullptr;
        RandomListNode* p = pHead;

        while(p){
            RandomListNode* p_next = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = p_next;
            p = p_next;
        }

        p = pHead;
        while(p){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
       
        RandomListNode* cloneHead = new RandomListNode(-1);
        RandomListNode* q = cloneHead;
        p = pHead;
        while(p){

            RandomListNode* p_next =p->next->next;
            q->next = p->next;
            q = q->next;
            p->next = q->next;
            p = p_next;
            
        }
        return cloneHead->next;
    }
    
};ss