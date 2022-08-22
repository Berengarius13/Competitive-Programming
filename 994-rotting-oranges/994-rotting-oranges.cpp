/*
* BFS and take care of edge cases !
*/
class Solution {
public:
    bool isValid (vector<vector<int>> &grid,int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(grid[x][y] == 0) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dirX = {1, 0, -1, 0};
        vector<int> dirY = {0, 1, 0, -1};
        int time = 0; 
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second; q.pop();
                
                for(int i = 0; i < 4; i++){
                    if(isValid(grid, x + dirX[i], y + dirY[i])){
                        grid[x+dirX[i]][y+dirY[i]] = 0;
                        q.push({x+dirX[i], y + dirY[i]});
                    }
                }
            }
            time++;
        }
        for(auto &it : grid){
            for(auto &num : it){
                if(num == 1){
                    return -1;
                }
            }
        }
        return (time <= 0) ? 0 : time-1;
    }
};