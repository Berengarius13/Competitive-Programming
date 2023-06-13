/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode * ans;

int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL) return 0;
    
    auto left = dfs(root->left, p, q);
    auto right = dfs(root->right, p, q);
    if(left == 4) return 4;
    if(right == 4) return 4;
    if(((left == 2 && right == 1) || (left == 1 && right == 2)) && ans == NULL){
        ans = root; 
        return 4;
    }
    if(root == p){
        if((left == 2 || right == 2) && ans == NULL){
            ans = root;
            return 4;
        }
    }
    if(root == q){
        if((left == 1 || right == 1) && ans == NULL){
            ans = root;
            return 4;
        }
    }
    
    if(p == root) return 1;
    if(q == root) return 2;
    
    return left + right;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        dfs(root, p, q);
        return ans;
    }
};