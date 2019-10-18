/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){

        ListNode* head=new ListNode(-1);
        ListNode* cur = head;
        int carry = 0;
        int val = 0;
        while(l1 && l2){
            val = l1->val + l2->val+carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 || l2){
            ListNode *p = l1? l1 : l2;
            while(p){
                val = p->val + carry;
                carry = val / 10;
                val = val % 10;
                cur->next = new ListNode(val);
                cur = cur->next;
                p= p->next;
            }
        }

        if(carry)
            cur->next = new ListNode(carry);
        return head->next;
    }
};