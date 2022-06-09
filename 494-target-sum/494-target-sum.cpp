class Solution {
public:
    int knapsack(vector<int>& nums, int &target, int i, int sum, unordered_map<int, map<int,int>> &mp){
        if(mp.find(i) != mp.end()){
            if(mp[i].find(sum) != mp[i].end()) return mp[i][sum];
        }
        if(i == nums.size() && sum == target) return 1;
        if(i == nums.size()) return 0;
    
        int left = knapsack(nums, target, i+1, sum+nums[i], mp);
        int right = knapsack(nums, target, i+1, sum-nums[i], mp);
        
        mp[i][sum] = left+right;
        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, map<int,int>> mp;
        return knapsack(nums, target, 0, 0, mp);
    }
};