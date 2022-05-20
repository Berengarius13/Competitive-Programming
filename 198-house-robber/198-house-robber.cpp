class Solution {
public:
    int max_sum;
    int rf(vector<int> &nums, int i,vector<int> &memo){
        if(i != -2)
            if(memo[i] != -1) return memo[i];
        int n = nums.size();
        if(i >= n) return 0;
        int doub_j = 0; int trip_j = 0;
        if(i + 2 < n)
            doub_j = rf(nums, i+2, memo);
        if(i+3 < n)
            trip_j = rf(nums, i+3, memo);
        
        if(i == -2) return max(doub_j, trip_j);
        memo[i]  = nums[i] + max(doub_j, trip_j);
        return nums[i] + max(doub_j, trip_j);
    }
    int rob(vector<int>& nums) {
        max_sum = 0;
        int maxi = nums[0];
        vector<int> memo(nums.size()+1, -1);
        max_sum =rf(nums, -2, memo);
        return max_sum;
    }
};