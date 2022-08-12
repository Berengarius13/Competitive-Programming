class Solution {
public:
    unordered_map<int, int> mp;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int curr = left+right+root->val;
        mp[curr]++;
        return curr;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int mx = INT_MIN;
        vector<int> ans;
        for(auto &[key, value] : mp)
            mx = max(mx, value);
        
        for(auto &[key, value] : mp){
            if(value == mx)
                ans.push_back(key);
        }
        return ans;
    }
};