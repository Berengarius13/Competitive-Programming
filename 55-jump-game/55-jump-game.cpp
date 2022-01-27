class Solution {
public:
    bool canReach(vector<int>& nums,int i,vector<int> &m){
        if(m[i]!=-1){
            return m[i];
        }
        if(i==nums.size()-1){
            return true;
        }
        for(int j=1;j<=nums[i]&&j+i<nums.size();j++){
            if(canReach(nums,i+j,m)){
                return m[i]=1;
            }
        }
        return m[i]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> m(10001,-1);
        return canReach(nums,0,m);
        
    }
};