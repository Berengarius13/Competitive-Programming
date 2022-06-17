
class Solution {
public:
    int count = 0;
    int dfs(TreeNode* node){
        if(node == NULL) return 2;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if((left * right) == 0){
            count++; return 1;
        }
        if(left == 1 || right == 1)
            return 2;
        if(left == 2 && right == 2) 
            return 0;
        return 2;
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0) count++;
        return count;
    }
};