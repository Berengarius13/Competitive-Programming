class Solution {
public:
    int mySqrt(int x) {
        long i = 1; long val = 1;
        while(val <= x){
            i++;
            val = i*i;
        }
        return i-1;
    }
};