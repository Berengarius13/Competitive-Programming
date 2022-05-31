
class Solution {
public:
    bool ans = true;
    int dfs(TreeNode* node, int i){
        if(node == NULL) return i;
        
        int left = dfs(node->left, i+1);
        int right = dfs(node->right, i+1);
        if(abs(left-right) > 1) ans = false;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};