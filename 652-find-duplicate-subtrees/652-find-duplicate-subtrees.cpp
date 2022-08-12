/*
* Make hash of string
* Use "("            ")" brackets so that
  hash is unique everytime
*   
*/
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, vector<TreeNode*>> mp;
    string dfs(TreeNode* root){
        if(root == NULL) return string();
        
        
        string curr = "("+ dfs(root->left) +to_string(root->val)+dfs(root->right) +")";
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