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
    vector<int> preorderTraversal(TreeNode* node) {
        vector<int> ans;
        stack<TreeNode*> stak;
        while(node!=NULL || !stak.empty()){
            while(node!= NULL){
            ans.push_back(node->val);
            stak.push(node);
            node = node->left;
        }
        node = stak.top();
        stak.pop();
        node = node->right;
    }
      return ans;  
    }
};