class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size()-1;
        int ans = -1;
        if(e ==0){
            if(nums[0]== target)
                return 0;
        }
        while(s<=e)
        {
            int m = (s+e)/2; 
            if(target < nums[m]){
                m--; 
                e=m;
            }
            else if(target > nums[m]){
                m++;
                s =m;
            }
            else
                return m;
        }
        return ans;
    }
};