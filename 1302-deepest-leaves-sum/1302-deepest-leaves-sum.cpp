
class Solution {
public:
    int max_i = 0;
    void dfss(TreeNode* node, int i){
        if(node == NULL) return;
        max_i = max(max_i, i);
        dfss(node->left, i+1);
        dfss(node->right, i+1);
    }
    int dfs(TreeNode* node, int &sum, int i){
        if(node == NULL) return 0;
        
        if(node->left == NULL && node->right == NULL && i == max_i){
            sum += node->val;
        }
        int a = dfs(node->left, sum, i+1);
        int b = dfs(node->right, sum, i+1);
        return 0;
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        dfss(root, 0);
        dfs(root, sum, 0);
        return sum;
    }
};