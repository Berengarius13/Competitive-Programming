
class Solution {
public:
    bool dfs(TreeNode* node, int targetSum, int sum){
        if(node == NULL) return false;
        sum = sum+node->val;
        if(sum == targetSum && node->left == NULL && node->right == NULL)
            return true;
        if(dfs(node->left, targetSum, sum)) return true;
        if(dfs(node->right, targetSum, sum)) return true;
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};