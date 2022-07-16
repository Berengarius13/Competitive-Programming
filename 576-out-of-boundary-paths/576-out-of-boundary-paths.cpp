class Solution {
public:
    int M = 1e9 + 7;
    int dfs(int &m, int &n, int maxMove, int i, int j, vector<vector<vector<int>>> &memo){
        if(i == m || j == n || i < 0 || j < 0) return 1;
        if(maxMove == 0) return 0;
        if(memo[i][j][maxMove] != -1) return memo[i][j][maxMove];
        int a = (dfs(m, n, maxMove-1, i, j+1, memo))%M;
        int b = (dfs(m, n, maxMove-1, i+1, j, memo))%M;
        int c = (dfs(m, n, maxMove-1, i, j-1, memo))%M;
        int d = (dfs(m, n, maxMove-1, i-1, j, memo))%M;
        
        memo[i][j][maxMove] = ((long)a+b+c+d)%M;
        return memo[i][j][maxMove];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m+1, vector<vector<int>> (n+1, vector<int> (maxMove+1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, memo);
    }
};