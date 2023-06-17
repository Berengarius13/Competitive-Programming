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
    bool dfs(TreeNode* root){
        if(root == NULL) return true;
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        if(root->val != 1 && root-> left == NULL && root->right == NULL) return false;
        if(root->val == 1 && root-> left == NULL && root->right == NULL) return true;
        return left + right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        auto x  = dfs(root);
        if(x == false) return NULL;
        return root;
    }
};