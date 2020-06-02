struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution {
public:
    int helper(TreeNode* root,int leftORright){
        if(root == nullptr) return 0;

        if(root->left == nullptr && root->right == nullptr){
            if(leftORright == 1){
                return root->val;
            }
            return 0;
        }

        return helper(root->left,1) + helper(root->right,2);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return 0;
        } 
        return helper(root->left,1) + helper(root->right,2); 
    }
};