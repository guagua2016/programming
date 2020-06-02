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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(n){
            fast = fast->next;
            n--;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;

        while(fast){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = slow->next;
        return dummy->next;
    }
};