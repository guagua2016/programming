#include <iostream>
#include <string>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution{
public:
    // char *Serialize(TreeNode* root){
    //     string res;
    //     if(root == nullptr) {
    //         res.push_back('#');
    //         return (char*)(res.c_str());
    //     }
       
    //     res += to_string(root->val);
    //     res.push_back(',');
    //     char* left = Serialize(root->left);
    //     char* right = Serialize(root->right);
    //     res = res + string(left) + string(right);
    //     return (char*)(res.c_str());
    // }

    char* Serialize(TreeNode *root) {
        if (root == nullptr) {
            return "#";
        }
        string r = to_string(root->val);
        r.push_back(',');
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
 
        char* ret = new char[strlen(left) + strlen(right) + r.size()];
        strcpy(ret, r.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }

    TreeNode* doDeserialize(char*& str){
        if(*str == '#') {
            str++;
            return nullptr;
        }
        int num = 0;
        while(*str!=','){
            num = 10*num + (*str - '0');
            str++;
        }
        str++;
        TreeNode* node = new TreeNode(num);
        node->left = doDeserialize(str);
        node->right = doDeserialize(str);
        return node;
    }

    TreeNode* Deserialize(char* str){
        return doDeserialize(str);
    }
};

int main(int argc, char const *argv[])
{
    char s[] = "fdsajfkds";
    std::cout << string(s) << std::endl;
    return 0;
}