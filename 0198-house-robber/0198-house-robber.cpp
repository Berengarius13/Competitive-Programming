#define vi vector<int>
class Solution {
public:
    int fun(vi &nums, vi &dp, int i){
        if(i >= nums.size())  return 0;
        // take
        if(dp[i] != -1) return dp[i];
        int a = nums[i] + fun(nums, dp, i+2);
        int b = fun(nums, dp, i+1);
        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        vi dp(nums.size() + 3, -1);
        return fun(nums, dp, 0);
    }
};