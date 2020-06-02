#include <string>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p){
                os << p->val << " ";
                q.push(p->left);
                q.push(p->right);
            }else{
                os << "# ";
            }
        }
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        istringstream in(data);

        string str;
        in >> str;
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(!(in >> str)) break;
            if(str != "#"){
                p->left = new TreeNode(stoi(str));
                q.push(p->left);
            }
            if(!(in >> str)) break;
            if(str != "#"){
                p->right = new TreeNode(stoi(str));
                q.push(p->right);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::cout << Codec().serialize(root) << std::endl;


    string str;
    istringstream in("1 2 3 # # 4 5 # # # #");
    char c = in >> str;
    std::cout << c << std::endl;



    return 0;
}