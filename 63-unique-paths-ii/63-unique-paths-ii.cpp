class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(grid[i][j] == 1) return 0;
        if(i == grid.size()-1 && j == grid[0].size()-1) return 1;
        
        int down = 0; int right = 0;
        if(i+1 < grid.size())
            down = dfs(grid, i+1, j, memo);
        if(j+1 < grid[0].size())
            right = dfs(grid, i, j+1, memo);
        
        memo[i][j] = down + right;
        return down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size()+1, vector<int> (grid[0].size()+1, -1));
        return dfs(grid, 0, 0, memo);
    }
};