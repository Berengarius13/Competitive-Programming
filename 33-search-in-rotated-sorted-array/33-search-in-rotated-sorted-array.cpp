class Solution {
public:
    /* *
     * Binary serch first to find break point
     * Break point is end of and start of non rotated array
     * Such that we have two sorted array 0, start and end, n
     * Then binary search on them
     */    
    int binary_search(vector<int> &nums, int s, int e, int &target){
        while(s<=e){
            int m = (s+e)>>1;
            if(nums[m] > target)
                e = m-1;
            else if(nums[m] < target)
                s = m+1;
            else
                return m;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end){
            int mid = (start+end)>>1;
            if(nums[mid] < nums[end])
                end = mid;
            else if(nums[mid] > nums[end])
                start = mid;
            if (start+1 == end)
                break;
        }
        
        int first_half = binary_search(nums, 0, start, target);
        int second_half = binary_search(nums, end, ((int)nums.size()-1), target);
        return max(first_half, second_half);
    }
};