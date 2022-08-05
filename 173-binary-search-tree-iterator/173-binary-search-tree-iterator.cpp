/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> nums;
    int i;
    
    void dfs(TreeNode* root){
        if(root == NULL) return;
        
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
        i = 0;
    }
    
    int next() {
        return nums[i++];
    }
    
    bool hasNext() {
        if(i >= nums.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */