class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // vector<int> ans; 
        // for(auto it : nums){
        //     if(it%2 == 0)
        //         ans.push_back(it);
        // }
        // for(auto it : nums){
        //     if(it%2 != 0)
        //         ans.push_back(it);
        // }
        // return ans;
        int c{0}, s{0}, l{};
        l = nums.size()-1;
        while(s <= l){
            if(nums[s]%2 == 0){
                s++;
            }
            else{
                swap(nums[s], nums[l]);
                l--;
            }
        }
        return nums;
    }
};