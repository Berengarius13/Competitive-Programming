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
class Solution {
public:
    int ans = INT_MAX;
    void dfs(TreeNode * node, int i){
        if(node == NULL) return;
        
        if(node->left == NULL && node->right == NULL)
            ans = min(ans, i);
        dfs(node->left, i+1);
        dfs(node->right, i+1);
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root, 1);
        return ans;
    }
};