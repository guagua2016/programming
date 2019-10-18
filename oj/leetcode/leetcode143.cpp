/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void PrintList(ListNode* head){
    ListNode* p = head;
    while(p){
        std::cout << p->val << '\t';
        p = p->next;
    }
    std::cout << std::endl;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p = head->next;
        ListNode* pre = head;
        while(p){
            pre->next = p->next;
            p->next = dummy->next;
            dummy->next = p;
        
            p = pre->next;
        }
        return dummy->next;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;
        // PrintList(fast);
        
        fast = reverseList(fast);
        
        // PrintList(fast);

        ListNode* p = head;
        ListNode* q = fast;

        ListNode* dummy = new ListNode(-1);
        ListNode* h = dummy;
        while(p || q ){
            if(p){
                h->next = p;
                p = p->next;
                h = h->next;
            }

            if(q){
                h->next = q;
                q = q->next;
                h = h->next;
            }
        }

        head = dummy->next;
    }
};