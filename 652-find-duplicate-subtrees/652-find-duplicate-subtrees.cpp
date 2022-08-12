
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, vector<TreeNode*>> mp;
    string dfs(TreeNode* root){
        if(root == NULL) return "N";
        
        string left = dfs(root->left);
        string right = dfs(root->right);
        
        string curr = " "+left +to_string(root->val)+right;
        mp[curr].push_back(root);
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        for(auto &it : mp){
            if(it.second.size()>= 2)
                ans.push_back(it.second[0]);
        }
        return ans;
    }
};