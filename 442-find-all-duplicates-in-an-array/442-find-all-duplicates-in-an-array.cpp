/*
* [1,N] trick
* Remember use -ve trick
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]) -1;
            if(nums[index] > 0)
                nums[index] = -1 * nums[index];
            else
                ans.push_back(index+1);
        }
        return ans;
    }
};