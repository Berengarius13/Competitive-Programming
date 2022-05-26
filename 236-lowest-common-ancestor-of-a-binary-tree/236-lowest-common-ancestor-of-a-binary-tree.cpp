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
        if(a&b){
            ans = node; return false;
        }
        if(a|b){
            if(node->val == p->val || node->val == q->val){
                ans = node; return false;
            }
        }
        
        if(node->val == p->val || node->val == q->val) return true;
        
        return a|b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root, p, q);
        return ans;
    }
};