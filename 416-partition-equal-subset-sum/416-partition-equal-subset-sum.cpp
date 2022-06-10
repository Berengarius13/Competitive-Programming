// Required subset twice is total sum
// Similar to 01 knapscak
class Solution {
public:
    bool knapsack(vector<int> &nums, int &total, int i, int sum, vector<vector<int>> &memo){
        if(memo[i][sum] != -1) return memo[i][sum];
        if(total-sum == sum) return true;
        if(i == nums.size()) return false;
        
        bool a = knapsack(nums, total, i+1, sum + nums[i], memo);
        bool b = knapsack(nums, total, i+1, sum, memo);
        
        memo[i][sum] = a|b;
        return a|b;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto &num : nums)
            total += num;
        if((total & 1) == 1) return false;
        vector<vector<int>> memo(nums.size()+2, vector<int> (total+2, -1));
        return knapsack(nums, total, 0, 0, memo);
    }
};