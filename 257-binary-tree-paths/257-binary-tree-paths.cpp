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
    vector<string> baap;
    void dfs(TreeNode* node, string ans){
        if(node == NULL) return;
        string num = to_string(node->val);
        ans += num;
        ans += "->";
        if(!node->left && !node->right){
            ans.pop_back(); ans.pop_back();
            baap.push_back(ans);
        }
        dfs(node->left, ans);
        dfs(node->right, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans;
        dfs(root, ans);
        return baap;
    }
};