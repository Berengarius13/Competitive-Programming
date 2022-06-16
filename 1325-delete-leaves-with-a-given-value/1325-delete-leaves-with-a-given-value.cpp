
class Solution {
public:
    TreeNode* dfs(TreeNode* node, int &target){
        if(node == NULL) return NULL;
        
        TreeNode* left = dfs(node->left, target);
        TreeNode* right = dfs(node->right, target);
        
        if(left == NULL && right == NULL && node->val == target) return NULL;
        
        node->left = left;
        node->right = right;
        
        return node;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};