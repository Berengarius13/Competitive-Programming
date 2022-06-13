class Solution {
public:
    int dfs(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        int m = triangle.size();
        if(i == m-1) return triangle[i][j];
         
        int left = INT_MAX; int right = INT_MAX;
        if(i+1 < m && j < triangle[i+1].size())
            left = dfs(triangle, i+1, j, memo);
        if(i+1 < m && j+1 < triangle[i+1].size())
            right = dfs(triangle, i+1, j+1, memo);
        
        memo[i][j] = triangle[i][j] + min(left, right);
        return triangle[i][j] + min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo(triangle.size(), vector<int> (triangle.size(), -1));
        return dfs(triangle, 0, 0, memo);
    }
};