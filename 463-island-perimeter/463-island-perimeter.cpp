class Solution {
public:
    int wall_hit_count = 0;
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            wall_hit_count++; return;
        }
        if(grid[i][j] == 0){
            wall_hit_count++; return;
        }
        if(grid[i][j] == 2) return;
        grid[i][j] = 2;
        
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    break;
                }
            }
        }
        return wall_hit_count;
    }
};