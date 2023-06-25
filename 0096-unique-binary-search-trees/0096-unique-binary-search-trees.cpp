class Solution {
public:
    int fun(int i, int j, vector<int> &dp){
        if(i > j) return 1;
        if(i == j) return 1;
        // node = k;s
        if(dp[j-i+1] != -1) return dp[j-i+1];
        int sum = 0;
        for(int k = i; k <= j; k++){
            int a = fun(i, k-1, dp);
            int b = fun(k+1, j, dp);
            sum += a*b;
        }
        return dp[j-i+1] = sum;
    }
    int numTrees(int n) {
        vector<int> nums;
        // for(int i = 1; i <= n; i++) nums.push_back(nums);
        vector<int> dp(n+2, -1);
        return fun(1, n, dp);
    }
};