/*
* a && (a ^ x) = a&x
* So individually looking at each bit in range from 32
we can surely say that we can convert 1 => 0 but not
0 => 1;
* So in ideal case we will unset every bit that can reduce
the value of final answer aka we want every bit of finaly 
answer to be 1
*/
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int set_count = 0; 
            int mask = 1 << i;
            for(auto num : nums)
                if(num & mask) set_count++;
            if(set_count) ans = ans | mask;
        }
        return ans;
    }
};