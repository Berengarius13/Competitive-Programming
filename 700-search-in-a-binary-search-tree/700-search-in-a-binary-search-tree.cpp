
class Solution {
public:
    TreeNode* ans = NULL;
    TreeNode* dfs(TreeNode* node, int &val){
        if(node == NULL) return NULL;
        if(node->val == val)
            ans = node;
        
        if(node->val > val)
            dfs(node->left, val);
        if(node->val < val)
            dfs(node->right, val);
        
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        dfs(root, val);
        return ans;
    }
};