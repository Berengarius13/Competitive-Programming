/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* root, TreeNode* p, TreeNode* q, int &num){
    if(root == NULL) return;
    dfs(root->left, p, q, num);
    dfs(root->right, p, q, num);
    if(p == root) num++;
    if(q == root) num++;
    // return left + right;
}
TreeNode * ans  = NULL;
void dfs2(TreeNode* root, TreeNode *p, TreeNode* q, int len, int RequiredDepth){
    if(root == NULL) return;
    int num = 0;
    dfs(root, p, q, num);
    if(num == 2){
        if(len > RequiredDepth){
            len = RequiredDepth;
            ans = root;
        }
    }
    dfs2(root->left, p, q, len+1, RequiredDepth);
    dfs2(root->right, p, q, len+1, RequiredDepth);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = root;
        dfs2(root, p, q, 0, INT_MIN);
        return ans;
    }
};