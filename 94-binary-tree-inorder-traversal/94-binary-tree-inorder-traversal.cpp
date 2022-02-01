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
    
    TreeNode* tree(TreeNode* root, vector<int> &ans){
        
        if(root->left != NULL) tree(root->left, ans);
        ans.push_back(root->val);
        if(root->right != NULL) tree(root->right, ans);
        return NULL;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans; 
        tree(root, ans);
        return ans;
    }
};