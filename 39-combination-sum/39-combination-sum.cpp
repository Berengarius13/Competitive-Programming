class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int begin, int sum, int target, vector<int> temp){
        if(sum > target) return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++){
            temp.push_back(nums[i]);
            sum += nums[i];
            dfs(nums, i, sum, target,temp);
            sum -= nums[i];
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, 0, 0,target,temp);
            return ans;
    }
};