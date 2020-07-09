struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution{
public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == nullptr) return true;
        TreeNode* mirrorRoot = mirror(pRoot);
        return isSameTree(pRoot,mirrorRoot);
    } 

    bool isSameTree(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1 == nullptr && pRoot2==nullptr) return true;
        if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
        return pRoot1->val == pRoot2->val && isSameTree(pRoot1->left,pRoot2->left) && isSameTree(pRoot1->right,pRoot2->right);
    }

    TreeNode*  mirror(TreeNode* pRoot){
        if(pRoot == nullptr) return nullptr;
        TreeNode* root = new TreeNode(pRoot->val);
        root->right = mirror(pRoot->left);
        root->left = mirror(pRoot->right);
        return root;
    }
};