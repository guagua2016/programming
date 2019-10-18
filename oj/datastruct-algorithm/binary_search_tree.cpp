#include <iostream>

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x) : key(x), left(nullptr), right(nullptr) {
    }
};

//recursive
BSTNode* search(BSTNode* root, int key) {
    if (root == nullptr)
        return nullptr;
    if (root->key == key)
        return root;
    else if (key < root->key)
        search(root->left, key);
    else
        search(root->right, key);
    return root;
}

BSTNode* search2(BSTNode* root, int key) {
    if (root == nullptr)
        return nullptr;
    BSTNode* cur = root;

    while (cur) {
        if (cur->key == key)
            break;
        else if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return cur;
}

//return true or false;
BSTNode* insert(BSTNode* root, int key) {
    BSTNode* insertNode = new BSTNode(key);


    if (root == nullptr) {
        root = insertNode;
    }

    BSTNode* cur = root;
    BSTNode* parent = nullptr;
    while (cur) {
        //when same key,false means insert failed.
        if (cur->key == key) return root;
        parent = cur;

        if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if(key < parent->key){
        parent->left = insertNode;
    }else{
        parent->right = insertNode;
    }
    return root;
}

//假设要删除的节点是p，
//分为三种情况：1）p是树叶；2）p只有一棵非空子树；3）p有两颗非空子树
BSTNode* erase(BSTNode* root, int key) {
    if (root == nullptr)
        return nullptr;

    if(key < root->key){
        root->left = erase(root->left,key);
    }else if(key > root->key){
        root->right = erase(root->right,key);
    }else{
        if(root->left == nullptr &&  root->right == nullptr){
            delete root;
            root = nullptr;
        }else if(root->left){
            BSTNode* p = root->left;
            while(p->right){
                p = p->right;
            }
            root->key = p->key;
            root->left = erase(root->left,root->key);
        }else{
            BSTNode* p = root->right;
            while(p->left){
                p = p->left;
            }
            root->key = p->key;
            root->right = erase(root->right,root->key);
        }
    }
    return root;
}

void print(BSTNode* root){
    if(root == nullptr) return;
    print(root->left);
    std::cout << root->key << '\t';
    print(root->right);
}

int main(){
    BSTNode* root = new BSTNode(3);
    insert(root,5);
    insert(root,4);
    insert(root,2);
    print(root);
    std::cout << std::endl;
    erase(root,4);
    print(root);
    return 0;
}