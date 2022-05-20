
class Solution {
public:
    int maze(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];
        
        int from_right = INT_MAX; int from_down = INT_MAX;
        
        if(i+1 < grid.size())
            from_down = maze(grid, i+1, j, memo);
        
        if(j+1 < grid[0].size())
            from_right = maze(grid, i, j+1, memo);
        memo[i][j] = grid[i][j] + min(from_right, from_down);
        return grid[i][j] + min(from_right, from_down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int> (grid[0].size(), -1));
        return maze(grid, 0, 0, memo);
    }
};