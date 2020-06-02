#include <iostream>
using namespace std;


// BST insert/delete/
//https://gist.github.com/harish-r/a7df7ce576dda35c9660

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution{
private:
    TreeNode* findMin(TreeNode* root){
        if(root == nullptr) return root;
        while(root->left){
            root = root->left;
        }
        return root;
    }


public:
    TreeNode* deleteNode(TreeNode* root,int key){
        TreeNode* temp;
        if(root == nullptr){
            return nullptr;
        }else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else if(root->left && root->right){   //
            temp = findMin(root->right);
            // std::cout << "===" << temp->val <<std::endl;
            root->val = temp->val;
            root->right = deleteNode(root->right,root->val);
        }else{
            temp = root;
            if(root->left == nullptr){
                root = root->right;
            }else if(root->right == nullptr){
                root = root->left;
            }
            delete temp;
        }
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root,int val){
        if(root == nullptr){
            root = new TreeNode(val);
        }else if(val < root->val){
            root->left = insertIntoBST(root->left,val);
        }else if(val > root->val){
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);

    TreeNode* ret = Solution().deleteNode(root,3);



    return 0;
}