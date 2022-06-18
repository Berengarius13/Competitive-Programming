class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--){
            int maxi = i+1; // Find maximum value after i
            for(int j = i+1; j < nums.size(); j++){
                if(nums[maxi] < nums[j]){
                    maxi = j;
                }
            }
            
            if(nums[i] >= nums[maxi]){
                for(int j = i+1; j < nums.size(); j++)
                    swap(nums[j], nums[j-1]); // this will sort
            }
            else{
                for(int j = i+1; j < nums.size(); j++)
                    if(nums[j] > nums[i]){
                        swap(nums[j], nums[i]);
                        return;
                }
            }
        }
    } 
};