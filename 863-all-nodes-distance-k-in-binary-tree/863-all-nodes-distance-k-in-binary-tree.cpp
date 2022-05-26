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
    vector<int> ans;
    int decide_dfs(TreeNode* node, TreeNode* target, int i, int &k){
        if(node == NULL) return 0;
        
        int a = decide_dfs(node->left, target, i+1, k);
        int b = decide_dfs(node->right, target, i+1, k);
        if(b){
            if(b-i == k) ans.push_back(node->val);
            dfs(node->left, b-i+1, k);
        }
        if(a){
            if(a-i == k)ans.push_back(node->val);
            dfs(node->right, a-i+1, k);
        }
        if(node->val == target->val){
            dfs(node, 0, k);
            return i;
        }
        return a+b;
    }
    void dfs(TreeNode* node, int i, int &k){
        if(node == NULL) return;
        if(i == k)
            ans.push_back(node->val);
        dfs(node->left, i+1, k);
        dfs(node->right, i+1, k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        decide_dfs(root, target, 0, k);
        return ans;
    }
};