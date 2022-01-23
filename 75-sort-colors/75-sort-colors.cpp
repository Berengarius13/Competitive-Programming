class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0; 
        int e = nums.size() -1;
        while(s<=e){
            if(nums[s] == 2){
                swap(nums[s], nums[e]);
                e--;
            }
            else
                s++;
        }
        s = 0;
        while(s<=e){
            if(nums[s] == 1){
                swap(nums[s], nums[e]);
                e--;
            }
            else
                s++;
        }
        
    }
};