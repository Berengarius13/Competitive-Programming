class Solution {
public:
    int absolute_max;
    int m_s(vector<int> &nums, int i){
        if(i == nums.size()) return 0;
        int res = max(nums[i], nums[i]+m_s(nums, i+1));
        absolute_max = max(res, absolute_max);
        return res;
    }
    int maxSubArray(vector<int>& nums) {
        absolute_max = nums[0];
        m_s(nums, 0);
        return absolute_max;
    }
};