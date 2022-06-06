class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size()-1;
        while(e>=s){
            int mid = (s+e)>>1;
            if(nums[mid] < target)
                s = ++mid;
            else if(nums[mid] > target)
                e = --mid;
            else{
                if(nums[s] < target)
                    s++;
                else if(nums[e] > target)
                    e--;
                if(nums[s] == target && nums[e] == target) break;
            }
        }
        vector<int> ans;
        if(s > e) ans = {-1, -1};
        else ans = {s , e};
        return ans;
    }
};