/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> nums;
    vector<int>::iterator cur;
public:
    void inOrder(TreeNode* root,vector<int>& ret){
        if(root == nullptr) return;
        inOrder(root->left,ret);
        ret.push_back(root->val);
        inOrder(root->right,ret);

    }

    BSTIterator(TreeNode* root) {
        inOrder(root,nums);
        cur = nums.begin();
    }
    
    /** @return the next smallest number */
    int next() {
        return *cur++;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != nums.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */