struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution{
public:
    bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
        return doHasSubtree(pRoot1,pRoot2);
    }

    bool doHasSubtree(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot2 == nullptr) return true;
        if(pRoot1 == nullptr) return false;

        return (pRoot1->val == pRoot2->val && doHasSubtree(pRoot1->left,pRoot2->left) && doHasSubtree(pRoot1->right,pRoot2->right)) \
                 || doHasSubtree(pRoot1->left,pRoot2) \
                 || doHasSubtree(pRoot1->right,pRoot2);
    }
};