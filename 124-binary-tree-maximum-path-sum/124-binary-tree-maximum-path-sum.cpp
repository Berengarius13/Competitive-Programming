class Solution {
public:
    int maximum(int a, int b, int c){
        int temp_a = max(a,b);
        int temp_b = max(b,c);
        return max(temp_a, temp_b);
        //return max(max(a,b), max(b,c));
    }
    int max_sum = INT_MIN;
    
    int dfs(TreeNode* node){
        if(node == NULL) return -10000;
        
        int b = dfs(node->left);
        int c = dfs(node->right);
        int parent_val = node->val;
        max_sum = max(max_sum, maximum(b, c, b+c+parent_val));
        int max_till_now = maximum(b+parent_val, c+parent_val, parent_val);
        if(max_till_now < 0) max_till_now = node->val;
        return max_till_now;
    }
    int maxPathSum(TreeNode* root) {
        int max_till_parent = dfs(root);
        max_sum = max(max_till_parent, max_sum);
        return max_sum;
    }
};