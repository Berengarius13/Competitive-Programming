
































/**
 * Same as unique path3 or word search
 * Just there is no backtrack here
 * We usually do backtrack to not messup grid
 * Here we want to mess it up so that is we just do casual dfs
 * We run to every corner of island and after doing it we make it 
 * DFS
 */

class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int i, int j){
        if(i< 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) 
            return false;
        if(grid[i][j] != '1') return false;
        grid[i][j] = '0';
        bool value = 
                    dfs(grid, i+1, j)
                    || dfs(grid, i, j+1) 
                    || dfs(grid, i-1, j)
                    || dfs(grid, i, j-1);
        
        // grid[i][j] = '1';
        return value;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};