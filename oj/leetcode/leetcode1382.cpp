/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void TraverseTree(TreeNode* root,vector<int>& vals){
        if(root == nullptr) return;
        vals.push_back(root->val);
        TraverseTree(root->left,vals);
        TraverseTree(root->right,vals);
    }
    
    TreeNode* help(vector<int>& vals,int left,int right){
        if(left > right) return nullptr;
        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = help(vals,left,mid-1);
        root->right = help(vals,mid+1,right);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        TraverseTree(root,vals);
        if(vals.size() < 2) return root;
        sort(vals.begin(),vals.end());
        return help(vals,0,vals.size()-1);
    }
};