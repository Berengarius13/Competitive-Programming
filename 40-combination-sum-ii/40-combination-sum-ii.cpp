/*
* Just like subset 2
*/
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int target, int begin,vector<int> temp){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(temp); return;
        }
        
        for(int i = begin; i < nums.size(); i++){
                if(i == begin || nums[i] != nums[i-1]){
                temp.push_back(nums[i]);
                dfs(nums, target-nums[i], i+1, temp);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0,temp);
        return ans;
    }
};