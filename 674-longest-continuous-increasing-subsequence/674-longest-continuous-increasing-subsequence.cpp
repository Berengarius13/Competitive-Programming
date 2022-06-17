class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 1;
        int count = 1;
        int max_count = 1;
        while(i < nums.size()){
            if(nums[i] > nums[i-1]){
                
                count++; i++;
            }
            else{
                count = 1; i++;
            }
            max_count = max(count, max_count);
        }
        return max_count;
    }
};