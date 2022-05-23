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
    int dfs(TreeNode* node, int i){
        if(node == NULL) return i;
        int a = 0; int b = 0;
        a = dfs(node->left, i+1);
        b = dfs(node->right, i+1);
        return max(a,b);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};