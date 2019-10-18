struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution{
public:
    int index  = 0;
    TreeNode* KthNode(TreeNode* root,int k){
        if(root == nullptr || k < 0){
            return nullptr;
        }
        TreeNode* left = KthNode(root->left,k);
        if(left) return left;
        index++;
        if(index == k){
            return root;
        }
        TreeNode* right = KthNode(root->right,k);
        if(right) return right;
        return nullptr;
    }
};