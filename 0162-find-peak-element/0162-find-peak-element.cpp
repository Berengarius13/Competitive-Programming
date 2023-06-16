class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()== 1) return 0;
        if(nums[0] > nums[1]) return 0;
        int n = nums.size();
        if(nums[n-1] > nums[n-2]) return n-1;
        int s = 1;
        int e = nums.size()-2;
        while(s <= e){
            int mid = (s+e) >> 1;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return s;
    }
};