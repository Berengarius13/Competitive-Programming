class Solution {
public:
    vector<vector<int>> ans;
    void knapsack(vector<int> &nums, int i, int target, int k, vector<int> temp)
    {   
        if(k == 0 && target == 0){
            ans.push_back(temp); return;
        }
        if(i == nums.size() || k == 0 || target == 0) return;
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            knapsack(nums, i+1, target-nums[i], k-1, temp);
            temp.pop_back();
        }
        knapsack(nums, i+1, target, k,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        knapsack(nums, 0, n, k, temp);
        return ans;
    }
};