/*
* No need to calculate running sum
* Just calculate the minim health needed
*/
class Solution {
public:
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == matrix.size() || j == matrix[0].size()) return INT_MAX;
        
        int right = dfs(matrix, i, j+1, memo);
        int down = dfs(matrix, i+1, j, memo);
        
        int mn = min(right, down);
        
        if(mn == INT_MAX)
            return memo[i][j] = max(1, 1-matrix[i][j]);
        
        return memo[i][j] = max(1, mn - matrix[i][j]);
        
        
    }
    int calculateMinimumHP(vector<vector<int>>& matrix) {
        
        vector<vector<int>> memo (matrix.size()+1, vector<int> (matrix[0].size()+1, -1));
        return dfs(matrix, 0, 0, memo); 
    }
};
