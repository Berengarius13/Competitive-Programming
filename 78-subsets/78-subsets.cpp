class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int begin, vector<int> temp)
    {
        ans.push_back(temp);
        
        for(int i = begin; i < nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(nums, i+1, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, 0, temp);
        return ans;
    }
};































































// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans; 
//         vector<int> temp_1; 
//         vector<int> temp_2;
//         temp_2.push_back(nums[0]);
//         ans.push_back(temp_1);
//         ans.push_back(temp_2);
//         for(int i = 1; i <nums.size(); i++){
//             int t_size = ans.size();
//             for(int j = 0; j < t_size; j++){
//                 vector<int> temp;
//                 temp = ans[j];
//                 temp.push_back(nums[i]);
//                 ans.push_back(temp);
//             }
//         }
//         return ans;
//     }
// };
/*
// More efficient method
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
}; 
*/