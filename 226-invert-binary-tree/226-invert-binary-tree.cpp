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
    TreeNode* dfs(TreeNode* node){
        if(node == NULL) return NULL;
        
        TreeNode* left = dfs(node->left);
        TreeNode* right = dfs(node->right);
        if(!left && !right) return node;
        node->left = right;
        node->right = left;
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};