class Solution {
public:
    int uknapsack(vector<int>& coins, int i, int amount, int count,vector<vector<int>> &memo){
        if(memo[i][amount] != -1) return memo[i][amount];
        if(amount == 0) return 1;
        if(i == coins.size()) return 0;
        
        
        int a = 0;
        if(coins[i] <= amount)
            a = uknapsack(coins, i, amount-coins[i],count+1 ,memo);
        
        int b = uknapsack(coins, i+1, amount, count,memo);
        
        memo[i][amount] = a+b;
        return a+b;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size()+1, vector<int> (amount+2, -1));
        return uknapsack(coins, 0, amount, 0,memo);
        
    }
};