
vector<TreeNode*> fun(vector<int> &nums,  int i, int j){
    if(i > j) return {NULL};
    vector<TreeNode*> cur;
    for(int k = i; k <= j; k++){
        
        auto left = fun(nums, i, k-1);
        auto right = fun(nums, k+1, j);
        for(int a = 0; a < left.size(); a++){
            for(int b = 0; b < right.size(); b++){
                cur.push_back(new TreeNode(nums[k], left[a], right[b]));
            }
        }
    }
    return cur;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nums = {0};
        for(int i = 1; i <= n; i++)nums.push_back(i);
        return fun(nums ,1, n);
    }
};

















































/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */