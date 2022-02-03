class Solution {
public:
    vector<vector<int>> ans;
    void rearr(vector<int> &nums,int b){
        if(b == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        for(int i = b; i < nums.size(); i++){
            swap(nums[b], nums[i]);
            rearr(nums, b+1);
            // We reset the swap
            swap(nums[b], nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        rearr(nums,0);
        return ans;
    }
};