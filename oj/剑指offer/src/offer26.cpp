struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == nullptr || (pRootOfTree->left==nullptr && pRootOfTree->right ==nullptr)){
            return pRootOfTree;
        }
        vector<TreeNode*> res = doConvert(pRootOfTree);
        return res[0];
    }

    vector<TreeNode*> doConvert(TreeNode* pRoot){
        vector<TreeNode*> res;
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;

        if(pRoot == nullptr) {
            res.push_back(head);
            res.push_back(tail);
            return res;
        }

        vector<TreeNode*> left = doConvert(pRoot->left);
        vector<TreeNode*> right = doConvert(pRoot->right);

        if(left[1] != nullptr){
            left[1]->right = pRoot;
            pRoot->left = left[1];
            head = left[0];
        }else{
            head = pRoot;
            pRoot->left = nullptr;
        }

        if(right[0] != nullptr){
            pRoot->right = right[0];
            right[0]->left = pRoot;
            tail = right[1];
        }else{
            pRoot->right = nullptr;
            tail = pRoot;
        }

        res.push_back(head);
        res.push_back(tail);
        return res;
    }
};