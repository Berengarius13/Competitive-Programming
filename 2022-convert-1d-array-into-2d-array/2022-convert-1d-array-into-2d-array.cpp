class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        vector<vector<int>> ans;
        if(nums.size() != m*n) return ans;

        int begin = 0;
        for(int i = 0; i < m; i++){
            vector<int> temp;
            int j = 0;
            for(j = begin; j < n*(i+1); j++){
                temp.push_back(nums[j]);
            }
            begin = j;
            ans.push_back(temp);
        }
        return ans;
    }
};