class Solution {
public:
    int max_col = 0;
    int min_col = 0;
    void dfs(TreeNode* node, int i, int col, unordered_map<int, unordered_map<int, vector<int>>> &mp){
        if(node == NULL) return;
        max_col = max(max_col, col);
        min_col = min(min_col, col);
        if(mp.find(col) == mp.end()){
            unordered_map<int, vector<int>> temp_map;
            vector<int> temp_vec = {node->val};
            temp_map.insert({i, temp_vec});
            mp.insert({col, temp_map});
            
        }           // mp[col] is a un_map
        else{
            // if(mp[col].find(i) == mp[col].end()){
            //     vector<int> temp_vec = {node->val};
            //     mp[col].insert({i, temp_vec});
            // }
            // else{
            //     mp[col][i].push_back(node->val);
            // }
             mp[col][i].push_back(node->val);
        }
        dfs(node->left, i+1, col-1, mp);
        dfs(node->right, i+1, col+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, unordered_map<int, vector<int>>> mp;
        /* col => {L => values<sorted>} */ 
        dfs(root, 0, 0, mp);
        vector<vector<int>> ans;
        for(int i = min_col; i <= max_col; i++){
            //auto temp_map = mp[i];
            vector<int> temp_vec;
            for(int j = 0; j < mp[i].size(); j++){
                //vector<int> vec_from_map = mp[i][j];
                sort(mp[i][j].begin(), mp[i][j].end());
                temp_vec.insert(temp_vec.end(), mp[i][j].begin(), mp[i][j].end() );
            }
            ans.push_back(temp_vec);
        }
        return ans;
    }
};