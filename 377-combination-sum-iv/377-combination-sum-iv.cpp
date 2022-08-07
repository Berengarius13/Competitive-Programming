class Solution {
 
    int dp[201][1001];
    int f(int i, int k , vector<int> & nums){
        if( i == nums.size()) return(k ==0);
        if(dp[i][k]!= -1 ) return dp[i][k];
        int p =0;
        int np = f(i+1 ,k,nums);
        if(k>=nums[i])
            p=f(0,k-nums[i],nums);
        return dp[i][k] =  p + np;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp,-1,sizeof(dp));
        return f(0,target , nums);
    }
};