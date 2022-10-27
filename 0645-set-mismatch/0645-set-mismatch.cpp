class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int sum_with_dup = 0;
        for(auto num:nums){
            sum_with_dup += num;
        }
        int rep;
        for(int i = 0; i < nums.size(); i++){
            nums[abs(nums[i])-1] *= -1;
            if(nums[abs(nums[i])-1] > 0){
                rep = abs(nums[i]);
                break;
            }
        }
        sum_with_dup -= rep;
        return {rep, sum - sum_with_dup};
    }
};