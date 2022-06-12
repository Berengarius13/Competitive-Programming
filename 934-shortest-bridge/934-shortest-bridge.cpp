/* *
 * Optimally you want to do bfs and dfs
 * Mark one island as visited  =2 and but them in queue
 * Then do level order traversal, with each rise in level
   signifying you are going closer to second island
 * Do BFS on grid  
 * Mark them as visited and return minimum
 * Find first 1;
 */
class Solution {
public:
    queue<pair<int,int>> q;
    void dfs(vector<vector<int>> &grid, int i, int j){
        int n = grid.size();
        if(i < 0 || j < 0 || i >= n || j >= n) return;
        if(grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push(make_pair(i,j));
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    int bfs(vector<vector<int>> &grid){
        int n = grid.size();
        vector<int> R = {1, 0, -1, 0};
        vector<int> C = {0, 1, 0, -1};
        int dist = INT_MAX;
        int d = 0;
        while(!q.empty()){
            int t = q.size();
            while(t > 0){
                int ii = q.front().first;
                int jj = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int ix = ii + R[i];
                    int jy = jj + C[i];
                    if(ix>=0 && ix<n && jy>=0 && jy<n && grid[ix][jy] == 1){
                        dist = min(d, dist);
                    }
                    if(ix>=0 && ix<n && jy>=0 && jy<n && grid[ix][jy] == 0){
                        q.push(make_pair(ix,jy));
                        grid[ix][jy] = 2;
                    }
                }
                t--; 
            }
            d++; 
        }
        return dist;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false; // Jus here to ensure for loop stops
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && flag == false){
                    dfs(grid, i, j);
                    flag = true; break;
                }
            }
            if(flag) break;
        }
        
        return bfs(grid);
    }
};