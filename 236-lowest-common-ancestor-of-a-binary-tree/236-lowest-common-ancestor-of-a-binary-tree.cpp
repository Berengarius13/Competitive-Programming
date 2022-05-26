/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return false;
        
        bool a = dfs(node->left, p, q);
        bool b = dfs(node->right, p, q);
        // If there is an lca in both subtree then this case
        if(a&b){
            ans = node; return false;
        }
        // If there is an lca in one tree then this case, compare with parent
        if(a|b){
            if(node->val == p->val || node->val == q->val){
                ans = node; return false;
            }
        }
        // return true if node is equal to either of them
        if(node->val == p->val || node->val == q->val) return true;
        
        // In any case return a|b;
        return a|b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root, p, q);
        return ans;
    }
};