#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    vector<vector<int>> Print(TreeNode* pRoot){
        vector<vector<int>> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if(pRoot == nullptr) return res;
        s1.push(pRoot);
        while(!s1.empty()){
            vector<int> v;
            if(res.size()%2==0){
                while(!s1.empty()){
                    TreeNode* t = s1.top();
                    s1.pop();
                    if(t->left)  s2.push(t->left);
                    if(t->right) s2.push(t->right);
                    v.push_back(t->val);
                }
            }else{
                while(!s1.empty()){
                    TreeNode* t = s1.top();
                    s1.pop();
                    if(t->right) s2.push(t->right);
                    if(t->left)  s2.push(t->left);
                    v.push_back(t->val);
                }
            }
            swap(s1,s2);
            res.push_back(v);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    return 0;
}