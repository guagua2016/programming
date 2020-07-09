struct TreeNode{
    TreeNode val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution
{
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber){
        vector<vector<int>> res;
        vector<int> curPath;
        doFindPath(root,curPath,expectNumber,res);
        return res;
    }
private:
    void doFindPath(TreeNode* root,vector<int> curPath,int expectNumber,vector<vector<int>>& res){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            if(expectNumber == root->val){
                curPath.push_back(root->val);
                res.push_back(curPath);
            }
            return;
        }
        curPath.push_back(root->val);
        doFindPath(root->left,curPath,expectNumber-root->val,res);
        doFindPath(root->right,curPath,expectNumber-root->val,res);
    } 
};