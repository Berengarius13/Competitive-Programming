class Solution {
public:
    int dfs(int s, int l, vector<int> &dp){
        if(s > l) return 0;
        if(s == l) return 1;
        if(dp[s] != -1) return dp[s];
        int a = dfs(s+1, l, dp);
        int b = dfs(s+2, l, dp);
        
        dp[s] = a + b;
        return a + b;
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return dfs(0, n, dp);
    }
};