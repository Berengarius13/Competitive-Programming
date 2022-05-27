class Solution {
public:
    /* Greedy Approach
    * We create a "Goal" pointer and set it end.
    * We check is it possible to reach from "goal -1", 
    * How do we check? Well we look at "max jump on 'goal-1'", then use that condition.
    * If yes we shift on place less until it reaches the first position
    * BTW we should start it from i-1, but it works either way, i-1 requires an extra condition
    */
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for(int i = goal; i >=0; i--){
            if(i + nums[i] >= goal)
                goal = i;
        }
        return goal == 0; 
    }
};


// //* Given below is the DP approach
// class Solution {
// public:
//     bool canReach(vector<int>& nums,int i,vector<int> &m){
//         if(m[i]!=-1){
//             return m[i];
//         }
//         if(i==nums.size()-1){
//             return true;
//         }
//         for(int j=1;j<=nums[i]&&j+i<nums.size();j++){
//             if(canReach(nums,i+j,m)){
//                 return m[i]=1;
//             }
//         }
//         return m[i]=0;
//     }
//     bool canJump(vector<int>& nums) {
//         vector<int> m(10000,-1);
//         return canReach(nums,0,m);
        
//     }
// };
