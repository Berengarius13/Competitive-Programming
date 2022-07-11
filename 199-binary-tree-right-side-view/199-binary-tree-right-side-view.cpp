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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(root == NULL) return ans;
        while(!q.empty()){
            int size = q.size();
            TreeNode* last = q.front();
            
            for(int i = 0; i < size; i++){
                last = q.front();
                q.pop();
                if(last->left)
                    q.push(last->left);
                if(last->right)
                    q.push(last->right);
            }
            ans.push_back(last->val);
        }
        return ans;
    }
};