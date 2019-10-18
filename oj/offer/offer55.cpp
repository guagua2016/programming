struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if(pHead == nullptr) return nullptr;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        do{
            if(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            }else{
                return nullptr;
            }

        }while(fast != slow);
      


        ListNode* meet = slow;
        fast = pHead;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    ListNode* pHead = nullptr;
    so.EntryNodeOfLoop(pHead);
    return 0;
}