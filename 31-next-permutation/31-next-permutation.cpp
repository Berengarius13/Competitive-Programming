class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--){
            
            // If maximum value is greater than i value
            // sort it with remaining value, aka put it in end
            // Cuz it is already sorted
            if(nums[i] >= nums[nums.size()-1]){
                for(int j = i+1; j < nums.size(); j++)
                    swap(nums[j], nums[j-1]); // this will sort
            }
            // Swap the i value with just greater value
            // We have our required array
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