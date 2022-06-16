/* *
 * Dfs with begin
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int begin, int &n, int &k, vector<int> &temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = begin; i <= n; i++){
            temp.push_back(i);
            dfs(i+1, n, k, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(1,n, k, temp);
        return ans;
    }
};