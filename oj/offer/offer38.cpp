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
    int TreeDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty()){
            if(q1.front()->left){
                q2.push(q1.front()->left);
            }
            if(q1.front()->right){
                q2.push(q1.front()->right);
            }
            q1.pop();
            if(q1.empty()){
                depth++;
                swap(q1,q2);
            }
        }
        return depth;
    }
};

