#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//https://www.cnblogs.com/grandyang/p/4913869.html
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         ostringstream os;
         serialize(root, os);
         return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }
    
    void serialize(TreeNode* root, ostringstream& os) {
        if (!root) os << "# ";
        else {
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }
    
    TreeNode* deserialize(istringstream& is) {
        string val = "";
        is >> val;
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(is);
        node->right = deserialize(is);
        return node;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}