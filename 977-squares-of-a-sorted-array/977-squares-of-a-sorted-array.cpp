class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &num: nums)
            num = abs(num);
        
        sort(nums.begin(), nums.end());
        
        for(auto &num: nums)
            num = num*num;    
       
       return nums;     
    }
};