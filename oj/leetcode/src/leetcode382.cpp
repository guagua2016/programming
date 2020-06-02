
#include <iostream>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val, i = 2;
        ListNode *cur = head->next;
        while (cur) {
            int j = rand() % i;
            if (j == 0) res = cur->val;
            ++i;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode *head;
};

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    std::cout << Solution(head).getRandom() << std::endl;

    return 0;
}