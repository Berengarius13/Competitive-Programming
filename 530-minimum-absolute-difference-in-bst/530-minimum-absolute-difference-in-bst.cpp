/*
* Remember previous difference
*/
class Solution {
public:
    int min_diff = INT_MAX;
    TreeNode* prev = NULL;
    void dfs(TreeNode* node){
        if(node == NULL) return;
        
        dfs(node->left);
        if(prev != NULL)
            min_diff = min(min_diff, abs(prev->val-node->val));
        prev = node;
        dfs(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return min_diff;
    }
};