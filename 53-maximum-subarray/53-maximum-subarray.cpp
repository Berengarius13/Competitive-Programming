class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int ans = INT_MIN;
        int maxi = 0;
        
        for(int i = 0; i< nums.size(); i++){
            
            
            maxi = maxi + nums[i];
            ans = max(maxi, ans);
            if(maxi < 0){
                maxi = 0;
            }
            
            
        }
        return ans;
    }
};