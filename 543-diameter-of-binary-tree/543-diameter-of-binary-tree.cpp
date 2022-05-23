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
    // Max sum is the variable which stores maximum sum between two branches
    int max_sum = 0;
    int dfs(TreeNode* node, int i){
        if(node == NULL) return 0;
        // Return the max depth of particular leaf node
        if(!node->left && !node->right)
            return i;
        int a = 0; int b = 0; // A is max len of left and b is max len of right after that node
        a = dfs(node->left, i+1);
        b = dfs(node->right, i+1);
        
        max_sum = max(max_sum, a + b - 2*i); // Subtrack 2*i to assume that node is center
        return max(a, b); // Return the max depth
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, 0);
        return max_sum;
    }
};