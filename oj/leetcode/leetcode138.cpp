/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head ==nullptr) return nullptr;
        Node* p = head;

        while(p){
            Node* t = new Node(p->val,p->next,nullptr);
            p->next = t;
            p = p->next->next;
        }

        p = head;
        while(p){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        Node* dummy = new Node(-1);
        Node* q = dummy;

        p = head;
        while(p){
            q->next = p->next;
            p->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        return dummy->next;
    }
};