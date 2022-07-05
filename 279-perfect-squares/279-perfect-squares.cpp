class Solution {
public:
    int unkapsack(vector<int> &boundary, int w, vector<vector<int>> &memo, int i){
        if(memo[i][w] != -1) return memo[i][w];
        
        if(w == 0) return 0;
        if(i == boundary.size()) return INT_MAX-1;
        
        int a = INT_MAX-1;
        if(boundary[i] <= w)
            a = 1 + unkapsack(boundary, w - boundary[i], memo,i);
        
        int b = unkapsack(boundary, w, memo, i+1);
        
        memo[i][w] = min(a,b);
        return min(a,b);
    }
    int numSquares(int n) {
        vector<int> boundary;
        for(int i = 1; i*i <=n ; i++)
            boundary.push_back(i*i);
        
        vector<vector<int>> memo(boundary.size()+1, vector<int> (n+1, -1));
        return unkapsack(boundary, n, memo, 0);
    }
};