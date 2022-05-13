class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int count = 0;
        // for(auto &num: nums)
        //     if(num == 0) count++;
        int s = 0;
        
        for(s = 0; s < nums.size(); s++){
            if(nums[s] == 0) break;
        }
        int e = s+1;
        while(s < nums.size() && e < nums.size()){
            if(nums[e] != 0){
                swap(nums[e], nums[s]);
                s++;
                e = s+1;
            }
            else{
                e++;
            }
        }
        return;
        
    }
};