class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int begin, vector<int> temp)
    {
        ans.push_back(temp);
        
        for(int i = begin; i < nums.size(); i++){
            if (i == begin || nums[i] != nums[i - 1]) { 
				temp.push_back(nums[i]);
				dfs(nums, i+1, temp);
				temp.pop_back();
			}
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, temp);
        return ans;
    }
};