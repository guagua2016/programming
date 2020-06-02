/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* p = head;
        ListNode* next = p->next;

        while(pre && p && p->next){
            next = p->next;

            p->next = next->next;
            next->next = p;
            pre->next = next;

            pre = p;
            p = p->next;
        }
        return dummy->next;
    }
};