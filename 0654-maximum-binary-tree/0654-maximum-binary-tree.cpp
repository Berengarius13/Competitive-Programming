class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int i, int j){
        if(i > j) return NULL;
        int id = 0;
        int mx = INT_MIN;
        for(int k = i; k <= j; k++){
            if(mx < nums[k]){
                mx = nums[k];
                id = k;
            }
        }
        // cout << mx << " " << id;
        TreeNode* left = dfs(nums, i, id-1);
        TreeNode* right = dfs(nums, id + 1, j);
        TreeNode* root = new TreeNode(mx, left, right);
        // TreeNode* root;
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};