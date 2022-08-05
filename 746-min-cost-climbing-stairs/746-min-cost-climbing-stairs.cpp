class Solution {
public:
    int jumpgame(vector<int> &cost, int i, vector<int> &memo){
        
        if(i >= cost.size()) return 0;
        
        if(memo[i] != -1) return memo[i];
        
        int a = cost[i] + jumpgame(cost, i+1, memo);
        int b = cost[i] + jumpgame(cost, i+2, memo);
        
        return memo[i] = min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo (cost.size()+1, -1);
        
        int a = jumpgame(cost, 0, memo);
        int b = jumpgame(cost, 1, memo);
        
        return min(a, b);
    }
};