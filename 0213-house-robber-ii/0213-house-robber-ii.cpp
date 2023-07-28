#define vi vector<int>
class Solution {
public:
    int fun(vi &nums, vector<vector<int>>  &dp, int i, int n){
        if(i >= n)  return 0;
        // take
        if(dp[i][n-nums.size()+1] != -1) return dp[i][n-nums.size()+1];
        if(i == 0) n--;
        int a = nums[i] + fun(nums, dp, i+2, n);
        if(i == 0) n++;
        int b = fun(nums, dp, i+1, n);
        return dp[i][n-nums.size()+1] = max(a, b);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>>  dp(nums.size() + 3, vector<int> (2, -1));
        return fun(nums, dp, 0, nums.size());
    }
};