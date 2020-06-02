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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr) return head;

        int length = 0;
        ListNode* p = head;
        while(p){
            length++;
            p = p->next;
        }
        k = k % length;
        if(k == 0) return head;

        ListNode* dummpy = new ListNode(-1);
        dummpy->next = head;
        p = dummpy;
        int step = length - k;
        while(step){
            p = p->next;
            step--;
        }

        if(p->next == nullptr) return head;

        dummpy->next = p->next;
        p->next = nullptr;
        p = dummpy->next;

        while(p->next){
            p = p->next;
        }
        p->next = head;

        return dummpy->next;
    }
};