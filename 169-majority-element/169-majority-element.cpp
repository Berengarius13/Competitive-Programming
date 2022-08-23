class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> setCount(32, 0);
        int n = nums.size();
        for(auto num : nums){
            unsigned int mask = 1;
            for(int i = 0; i < 32; i++){
                if((num & mask)){
                    setCount[i]++;
                }
                mask = mask << 1;
            }
        }
        int ans = 0; 
        for(unsigned int i = 0, mask = 1 ; i < 32; i++, mask = mask << 1){
            if(setCount[i] > n/2){
                ans |= mask;
            }
        }
        return ans;
    }
};