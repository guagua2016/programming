class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return help(pRoot,depth);
    }

private:
    bool help(TreeNode* pRoot,int& depth){
        if(pRoot == nullptr) {
            depth = 0;
            return true;
        }
        
        int leftDepth,rightDepth;
        if(help(pRoot->left,leftDepth) && help(pRoot->right,rightDepth)){
            if(abs(leftDepth-rightDepth) < 2){
                depth = max(leftDepth,rightDepth) + 1;
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};