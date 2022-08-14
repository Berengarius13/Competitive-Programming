/*
* Write a returning recursion which builds solution
* Use The mcm variation
* Think from base case and build to the solution
* Use bst 1 to come up with solution
*/
class Solution {
public:
     vector<TreeNode*> dfs(int i, int j, vector<int> &nums){
        if(i > j) return {NULL};
        vector<TreeNode*> temp;
        for(int k = i; k <= j; k++){
            
            vector<TreeNode*> left_tree = dfs(i, k-1, nums);
            vector<TreeNode*> right_tree = dfs(k+1, j, nums);
            for(auto left : left_tree){
                for(auto right : right_tree){
                    TreeNode* curr = new TreeNode(nums[k], left, right);
                    temp.push_back(curr);
                }
            }
        }
        return temp;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        vector<TreeNode*> ans;
        return dfs(0, nums.size()-1, nums);
    }
};