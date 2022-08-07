class Solution {
public:
    int uknapsack(vector<int> &nums, int i, int target, vector<vector<int>> &memo){
        if(target == 0) return 1;
        if(i == nums.size()) return 0;
        if(memo[i][target] != -1) return memo[i][target];
        int a = 0;
        if(nums[i] <= target){
            a = uknapsack(nums, 0, target-nums[i], memo);
        }
        int b = uknapsack(nums, i+1, target, memo);
        
        return memo[i][target]=a+b;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size()+1, vector<int> (target+1, -1));
        return uknapsack(nums, 0, target,memo);
    }
};