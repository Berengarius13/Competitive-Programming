class Solution {
public:
    vector<vector<int>> ans;
    void ubknapsack(vector<int>& nums, int i,int target, vector<int> temp){
        if(target == 0){
            ans.push_back(temp); return;
        }
        if(i == nums.size()) return;
        
        int a = 0;
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            ubknapsack(nums, i,target-nums[i], temp);
            temp.pop_back();
        }
        ubknapsack(nums, i+1,target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        ubknapsack(nums, 0,target, temp);
        return ans;
    }
};