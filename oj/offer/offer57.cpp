struct TreeLinkNode{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x) : left(nullptr),right(nullptr),next(nullptr){}
}

class Solution{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pRoot){
        if(pRoot == nullptr ) return nullptr;

        if(pRoot->right){
            TreeLinkNode* p = pRoot->right;
            while(p->left){
                p = p->left;
            }
            return p;
        }
        if(pRoot->next){
            if(pRoot->next->left == pRoot){
                return pRoot->next;
            }
            if(pRoot == pRoot->next->right && pRoot->next->next && pRoot->next == pRoot->next->next->left){
                return pRoot->next->next;
            }
        }
        return nullptr;
    }
};