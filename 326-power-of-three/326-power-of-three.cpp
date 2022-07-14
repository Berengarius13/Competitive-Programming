/*
* Calculate max power of 3
* Make use of it, all the powers of 3 will be
divisible by it
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int max_pow = pow(3, 19);
        return max_pow % n == 0;
    }
};