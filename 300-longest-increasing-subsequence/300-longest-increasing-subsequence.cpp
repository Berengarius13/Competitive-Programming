/***
 * RECURSION ANALYSIS (Aim to cover every possibility)
 * Divdie it into two case 
   "If next value is greater than previous greatest" and
    inverse of this case
 * True: 
    CASE 1: WE CONSIDER IT [1,2,3,4]
    count increases as well as maximum value get updated
    CASE 2: WE DON'T CONSIDER IT [4,1,2,3] > don't want to miss 
    count remain same, as well as previous maximum
   False:
    CASE 1: WE CONSIDER IT [444, 1,2,4]
    count again starts from 1, and maximum get updated
    Why? if we want to be part of a valid subsequenc then
    it is the only method to do so, As we can't count it 
    as part of previous sequence, as it voilates the condition
    CASE 2: WE DON'T CONSIDER IT [1,333, 2, 3] > don't want to miss
    count remain same, as well as previous maximum
 * Did you notice case 2 get's repeated?
 * So Make case 2 out of if else 
 * Pretty difficuilt to think on your own right?
 * LEARNING !!!
    Well make every possibility, eliminate duplicates
    group similar and assume these are not true {think through ex.}
    then make sure these hold true everywhere !!
 */



class Solution {
public:
    int max_count = 0;
    int dfs(vector<int>& nums, int j, vector<int> &memo){
        if(j == (nums.size()-1)) return 1;
        if(memo[j] != -1) return memo[j];
        int maxi = 1;
        for(int i = j+1; i < nums.size(); i++){
            if(nums[i]> nums[j]){
                maxi = max(dfs(nums, i, memo)+1, maxi);
            }
        }
        memo[j] = maxi;
        return memo[j];
    }
    int lengthOfLIS(vector<int>& nums) {
        //vector<vector<int>> memo (nums.size(), vector<int> (nums.size(), -1));
        vector<int> memo (nums.size(), -1);
        int ans = 1;
        for(int i = 0; i < nums.size(); i++){
            ans = max(dfs(nums , i, memo), ans);
        }
        
        for(auto it: memo)
            cout<< it << " ";
        return ans;
    }
};




































































/*
class Solution {
public:
    int COUNT = 1; 
    void lcs(vector<int> &nums, int i, int prev, int c){
        if(i == (nums.size()-1)){
            COUNT = max(COUNT, c);
            return;
        }
        if(nums[i+1] > nums[prev]){
            lcs(nums, i+1, i+1, c+1); // We update the prev as well as count
        }
        else{
            lcs(nums, i+1, i+1, 1);
        }
       lcs(nums, i+1, prev, c);
    }
    int lengthOfLIS(vector<int>& nums) {
        lcs(nums, 0, 0, 1);
        return COUNT;
    }
};
*/




/*
class Solution {
public:
    int COUNT = 1; 
    void lcs(vector<int> &nums, int p, int maxi, int c){
        if(p == (nums.size()-1)){
            COUNT = max(COUNT, c);
            return;
        }
        
        lcs(nums, p+1, maxi, c);
        
        if(nums[p+1] > maxi){
            maxi = nums[p+1];
            lcs(nums, p+1, maxi, c+1);
        }
        
    }
    int lengthOfLIS(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            lcs(nums, i, nums[i], 1);
        }
        // lcs(nums, 0, nums[0], 1);
        return COUNT;
    }
};
*/
/* unable to memorize
int COUNT = 1; 
    
    void lcs(vector<int> &nums, int p, int maxi, int c, vector<vector<int>> &v){
        if(v[abs(maxi)][p]>= c) return;
        if(p == (nums.size()-1)){
            v[abs(maxi)][p] = max(v[abs(maxi)][p], c);
            COUNT = max(COUNT, c);
            return;
        }
        if(nums[p+1] > maxi){
            // if(v[nums[p+1]][c+1]==1) return;
            lcs(nums, p+1, nums[p+1], c+1, v);
        }
        else{
            // if(v[nums[p+1]][1]== 1)return;
            lcs(nums, p+1, nums[p+1], 1, v);
        }
        lcs(nums, p+1, maxi, c, v);
        v[abs(maxi)][p] = max(v[abs(maxi)][p], c);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int maximum = INT_MIN;
        for(auto &it : nums){
            it = it + 2500;
            maximum = max(abs(it), maximum);
            
        }
        vector<int> temp(nums.size()+1, 0);
        vector<vector<int>> v (maximum+1, temp);
        // // for(int i = 0; i < nums.size(); i++){
        // //     lcs(nums, i, nums[i], 1);
        // // }
        // vector<int> vv(25002, 0);
        lcs(nums, 0, nums[0], 1, v);
        return COUNT;
    }
*/