class Solution {
public:
    bool dfs(vector<int> &nums, int i, vector<int> &square, int &k){
        if(i == nums.size()){
            return true;
        }
        
        
        for(int p = 0; p < square.size(); p++){
            square[p] += nums[i];
            if(square[p] <= k){
                if(dfs(nums, i+1, square, k)) return true;
            }
            square[p] -= nums[i];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater <>());
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(nums.size() < 4 || sum % 4 != 0 ) return false;
        sum = sum/4;
        vector<int> square(4, 0);
        if(dfs(nums, 0, square, sum)) return true;
        return false;
    }
};