/*
* Use array indices as a way to store information if a value have occured
in an array or not
* like [1,1,1,1,0,0]
* Use negative sign to represent that value have occured (index)
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i])-1;
            if(nums[index] > 0)
                nums[index] = -1 * nums[index];
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                ans.push_back(i+1);
        return ans;
    }
};