#include <stack>
#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL){}
};
 

void printList(ListNode* head){
    ListNode* p = head;
    while(p){
        std::cout << p->val << '\t';
        p = p->next;
    }
    std::cout << std::endl;
}

//slow fast pointer and stack
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;


        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = slow->next;
        stack<int> s;
        while(p){
            s.push(p->val);
            p = p->next;
        }

        p = head;
        while(!s.empty()){
            if(p->val != s.top()){
                return false;
            }
            s.pop();
            p = p->next;
        }
        return true;
    }
};


// reverse list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = slow->next;
        ListNode* p = slow->next->next;
        while(p){
            pre->next = p->next;
            p->next = slow->next;
            slow->next = p;
            p = pre->next;
        }
        // printList(head);
        p = slow->next;
        ListNode* q = head;

        while(p){
            if(q->val != p->val){
                return false;
            }else{
                q = q->next;
                p = p->next;
            }
        }
        return true;
    }
};




int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    std::cout << Solution().isPalindrome(head) << std::endl;
    return 0;
}
