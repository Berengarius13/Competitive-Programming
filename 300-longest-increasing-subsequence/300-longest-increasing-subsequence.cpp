class Solution {
public:
    int lis(vector<int> &nums, int i, int j, vector<vector<int>> &memo){
        if(i == nums.size() || j == nums.size()) return 0;
        if(memo[i][j+1] != -1) return memo[i][j+1];
        int a = 0;
        if(j == -1 || nums[i] > nums[j]){
            a = 1 + lis(nums, i+1, i, memo);
        }
       
        int b = lis(nums, i+1, j, memo);
        
        return memo[i][j+1] = max(a, b);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size()+1, vector<int> (nums.size()+1, -1));
        return lis(nums, 0, -1, memo);
    }
};