/*
* Power of 4 is power of 2
* Power of 4 - 1, is divisible by 3 can be prooved
using binomial theorem
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};