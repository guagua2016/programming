struct ListNode{
    int val;
    ListNode* next;
    ListNode(x):val(x),next(nullptr){}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
    }
};