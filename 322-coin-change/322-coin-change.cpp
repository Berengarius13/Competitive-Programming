class Solution {
public:
    int uknapsack(vector<int>& coins, int i, int amount, int count,vector<vector<int>> &memo){
        if(memo[i][amount] != -1) return memo[i][amount];
        if(amount == 0) return 0;
        if(i == coins.size()) return 1000000;
        
        
        int a = 1000000;
        if(coins[i] <= amount)
            a = 1+ uknapsack(coins, i, amount-coins[i],count+1 ,memo);
        
        int b = uknapsack(coins, i+1, amount, count,memo);
        
        memo[i][amount] = min(a,b);
        return min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size()+1, vector<int> (amount+2, -1));
        int ans = uknapsack(coins, 0, amount, 0,memo);
        if(ans < 1000000) 
            return ans;
        else
            return -1;
    }
};