/*
* Bit Manupulation
* If xor have set bit that means that it must have 
been xorred by two numbers with bits as 0 ^ 1 or 1 ^ 0
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(auto num : nums)
            xorr = xorr ^ num;
        int right_most_bit = (xorr & ((long)xorr-1)) ^ xorr;
        int ans1 = 0; int ans2 = 0;
        for(auto &num : nums){
            if(num & right_most_bit)
                ans1 ^= num;
            else
                ans2 ^= num;
        }
        return {ans1, ans2};
    }
};