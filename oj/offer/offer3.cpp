/*
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
- reverse list
- recursive
*/


#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> res;
        if(head == NULL){
            return res;
        }else if(head->next ==NULL){
            res.push_back(head->val);
            return res;
        }

        ListNode *former = head;
        ListNode *p = head->next;
        former->next = NULL;
        while(p->next){
            ListNode* after = p->next;
            p->next = former;
            former = p;
            p = after; 
        }
        p->next = former;
        head = p;
        while(p){
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
};


int main(){
    Solution so;

    ListNode* head = new ListNode(-1);
    head->next = new ListNode(-2);
    head->next->next = new ListNode(-3);
    vector<int> res = so.printListFromTailToHead(head);

    for(int i=0;i<res.size();i++){
        std::cout << res[i] << '\t';
    }
    std::cout << std::endl;
}