/*
* Brian Kernighan Algorithm
* Remember when you reduce a number by 1 all digits till right most
set bit toggle including that set bit
* Verify yourself
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n = (n &(n-1));
        }
        return count;    
    }
};