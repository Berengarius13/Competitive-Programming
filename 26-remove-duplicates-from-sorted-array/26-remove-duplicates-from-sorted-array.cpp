class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int b = 0; 
        for(int a = 0; a+1 < nums.size(); a++){
            if(nums[a] != nums[a+1])
                nums[++b] = nums[a+1];
        }
        return b+1;
    }
};