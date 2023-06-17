class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return  nums[n-1];
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e){
            int mid = (s+e) >> 1;
            if(nums[mid] == nums[mid+1]){
                if((mid - s)&1){
                    e = mid - 1;
                }
                else{
                    s = mid + 2;
                }
            }
            else if(nums[mid] == nums[mid - 1]){
                if((mid-1 - s)&1){
                    e = mid - 2;
                }
                else{
                    s = mid + 1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[s];
    }
};