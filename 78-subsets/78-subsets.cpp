class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> temp_1; 
        vector<int> temp_2;
        temp_2.push_back(nums[0]);
        ans.push_back(temp_1);
        ans.push_back(temp_2);
        for(int i = 1; i <nums.size(); i++){
            int t_size = ans.size();
            for(int j = 0; j < t_size; j++){
                vector<int> temp;
                temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};