class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int begin){
        if(begin == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            swap(nums[i], nums[begin]);
            dfs(nums, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};