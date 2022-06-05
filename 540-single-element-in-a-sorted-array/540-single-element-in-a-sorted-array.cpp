class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e =  nums.size()-2;
        while(e>s){
            if(nums[s] != nums[s+1])
                return nums[s];
            if(nums[e] != nums[e+1])
                return nums[e+1];
            int m = (s+e)/2;
            if(nums[m] == nums[m-1]) m--;
            if(nums[m] == nums[m+1]){
                if(((m-s)&1) == 1)
                    e = m-2;
                else
                    s = m+2;
            }
            else{
                if(((m-s)&1) == 1)
                    return nums[m+1];
                else
                    return nums[m];
            }
        }
        return nums[0];
    }
};