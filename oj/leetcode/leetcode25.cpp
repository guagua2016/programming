#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL){}
};


void printList(ListNode* head){
    ListNode* p = head;
    while(p){
        std::cout << p->val << '\t';
        p = p->next;
    }
    std::cout << std::endl;
}

class Solution {
public:

    ListNode* helper(ListNode* head,ListNode* end){
        end->next = nullptr;

        if(head == nullptr || head == end) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = head;
        ListNode* p = head->next;
        ListNode* next = p->next;

        while(p){
            pre->next = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = pre->next; 
            printList(dummy->next);
        }

        return dummy->next;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        ListNode* q;
        while(p){
            q = p;
            int n = k;
            while(--n && q){
                q = q->next;
            }
            if(q == nullptr){
                break;
            }
            ListNode* t = q->next;
            pre->next = helper(p,q);
            pre = p;
            p->next = t;
            p = t;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* r1 = Solution().reverseKGroup(head,2);
    printList(r1);
    return 0;
}