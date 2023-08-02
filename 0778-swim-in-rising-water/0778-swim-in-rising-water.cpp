#define pii pair<int, pair<int,int>>
#define vvi vector<vector<int>> 
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue <pii, vector<pii>, greater<pii> > pq;  
        pq.push({grid[0][0], {0, 0}});
        vvi dp(grid.size(), vector<int> (grid.size(), INT_MAX));
        dp[0][0] = grid[0][0];
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int w = t.first;
            int x = t.second.first;
            int y = t.second.second;
            int i = x;
            int j = y;
            if(x + 1 < n && max(grid[i+1][j], w) < dp[i+1][j]){
                dp[i+1][j] = max(grid[i+1][j], w);
                pq.push({max(grid[i+1][j], w), {i+1, j}});
            }
            if(y + 1 < n && max(grid[i][j+1], w) < dp[i][j+1]){
                dp[i][j+1] = max(grid[i][j+1], w);
                pq.push({max(grid[i][j+1], w), {i, j+1}});
            }
            if(x - 1 >= 0 && max(grid[i-1][j], w) < dp[i-1][j]){
                dp[i-1][j] = max(grid[i-1][j], w);
                pq.push({max(grid[i-1][j], w), {i-1, j}});
            }
            if(y - 1 >=0 && max(grid[i][j-1], w) < dp[i][j-1]){
                dp[i][j-1] = max(grid[i][j-1], w);
                pq.push({max(grid[i][j-1], w), {i, j-1}});
            }
        }
        return dp[n-1][n-1];
    }
};