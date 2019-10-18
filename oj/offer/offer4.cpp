/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()){
            return NULL;
        }else if(pre.size() == 1){
            return new TreeNode(pre[0]);
        }
        TreeNode* root = new TreeNode(pre[0]);
        vector<int> left_pre,right_pre;
        vector<int> left_vin,right_vin;
        int flag = 0;
        for(int i=0;i<pre.size();i++){
            if(vin[i] == pre[0]){
                flag = 1;
            }else if(flag == 0){
                left_pre.push_back(pre[i+1]);
                left_vin.push_back(vin[i]);
            }else {
                right_pre.push_back(pre[i]);
                right_vin.push_back(vin[i]);
            }
        }
        root->left = reConstructBinaryTree(left_pre,left_vin);
        root->right = reConstructBinaryTree(right_pre,right_vin);
        return root;
    }
};