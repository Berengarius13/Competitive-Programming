#define ll long long
#define vll vector<vector<long long>>
class Solution {
public:
    ll fun(int n, int m, vll &grid, vll &dp, int x, int y){
        if(x == n-1 && y == m-1) return 1;
        if(x == n || y == m) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        grid[x][y] = 0;
        ll ways = 0;
        // down
        if(x + 1 < n && grid[x+1][y] == 0){
            ways = fun(n, m, grid, dp, x+1, y);
        }
        // right
        if(y + 1 < m && grid[x][y+1] == 0){
            ways += fun(n, m, grid, dp, x, y+1);
        }
        dp[x][y] = ways;
        return ways;
    }
    int uniquePaths(int m, int n) {
        vll grid(m, vector<ll> (n, 0));
        vll dp(m, vector<ll> (n, -1));
        return fun(m, n, grid, dp, 0, 0);
    }
};