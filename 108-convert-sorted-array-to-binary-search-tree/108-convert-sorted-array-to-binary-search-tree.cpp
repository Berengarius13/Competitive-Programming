/**
 * Make range and root variable
 * If sum of range is odd root is n/2+1
 * if range is even n/2 is root
 */

class Solution {
public:
    bool isodd(int num){
        if(((num)&1) == 1) return true;
        else return false;
    }
    TreeNode* build(vector<int> &nums, int root, pair<int,int> range){
        if(range.first>range.second) return NULL;
        TreeNode* node = new TreeNode(nums[root]);
        pair<int,int> right_range = {root+1, range.second};
        pair<int,int> left_range = {range.first, root-1};
        int root_left, root_right;
        if(isodd(left_range.first+left_range.second))
            root_left = ((left_range.first+left_range.second)/2)+1;
        else
            root_left = (left_range.first+left_range.second)/2;
        if(isodd(right_range.first+right_range.second))
            root_right = ((right_range.first+right_range.second)/2)+1;
        else
            root_right = (right_range.first+right_range.second)/2;
        
        TreeNode* left = build(nums, root_left, left_range);
        TreeNode* right = build(nums, root_right, right_range);
        
        node->left = left;
        node->right = right;
        
        return node;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int root = 0;
        if((nums.size()-1)&1 == 1)
            root = ((nums.size()-1)/2)+1;
        else
            root = (nums.size()-1)/2;
        pair<int,int> range = {0, nums.size()-1};
        return build(nums, root, range);
    }
};