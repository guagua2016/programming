#include <vector>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

void preOrder(TreeNode* root,vector<int>& res){
    if(root == nullptr) return;
    res.push_back(root->val);
    preOrder(root->left,res);
    preOrder(root->right,res);
}

void inOrder(TreeNode* root,vector<int>& res){
    if(root == nullptr) return;
    inOrder(root->left,res);
    res.push_back(root->val);
    inOrder(root->right,res);
}

void postOrder(TreeNode* root,vector<int>& res){
    if(root == nullptr) return;
    postOrder(root->left,res);
    postOrder(root->right,res);
    res.push_back(root->val);
}


vector<int> preOrder(TreeNode* root){
    vector<int> res;
    if(root == nullptr) return res;

    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(cur || !st.empty()){
        while(cur){
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        }
        if(!st.empty()){
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
    return res;
}


vector<int> inOrder(TreeNode* root){
    vector<int> res;
    if(root==nullptr) return res;

    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        if(!st.empty()){
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
    return res;
}


vector<int> postOrder(TreeNode* root){
    vector<int> res;
    if(root == nullptr) return res;

    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(cur){
        st.push(cur);
        cur = cur->left;
    }

    TreeNode* lastVisited = nullptr;
    while(!st.empty()){
        cur = st.top();
        st.pop();
        if(cur->right == nullptr || cur->right == lastVisited){
            res.push_back(cur->val);
            lastVisited = cur;
        }else{
            st.push(cur);
            cur = cur->right;
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
        }
    }
    return res;
}

vector<int> levelOrder(TreeNode* root){
    vector<int> res;
    if(root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        size_t n = q.size();
        for(size_t i=0;i<n;i++){
            TreeNode* cur = q.back();
            q.pop();
            res.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return res;
}