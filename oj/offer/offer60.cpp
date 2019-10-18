#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    vector<vector<int>> Print(TreeNode* pRoot){
        vector<vector<int>> res;
        if(pRoot == nullptr) return res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(pRoot);
        while(!q1.empty()){
            vector<int> v;
            while(!q1.empty()){
                TreeNode* t = q1.front();
                q1.pop();
                if(t->left) q2.push(t->left);
                if(t->right) q2.push(t->right);
                v.push_back(t->val);
            }
            res.push_back(v);
            swap(q1,q2);
        }
        return res;
    } 
};