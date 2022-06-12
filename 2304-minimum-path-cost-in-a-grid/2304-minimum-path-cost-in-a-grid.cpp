class Solution {
public:
    int maze (vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j, vector<vector<int>> &memo){
        int n = grid[0].size();
        int m = grid.size();
        if(memo[i][j] != -1) return memo[i][j];
        if(i == m-1)
            return grid[i][j];
        
        
        int next = INT_MAX;
        for(int k = 0; k < grid[0].size(); k++){
            next = min( next,moveCost[grid[i][j]][k]   + maze(grid, moveCost, i+1, k, memo));
        }
        
        
        memo[i][j] = grid[i][j] + next;
        return grid[i][j] + next;
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> memo(grid.size(), vector<int> (grid[0].size(), -1));
        int ans = INT_MAX;
        for(int j = 0; j < grid[0].size(); j++){
            ans = min(ans, maze(grid, moveCost,0, j, memo));
        }
        return ans;
    }
};