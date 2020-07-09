#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root){
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* p = root;
        while(!q.empty()){
            p = q.front();
            q.pop();
            res.push_back(p->val);
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
        return res;
    }
};