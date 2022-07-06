class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1; long val = 1;
        while(val <= num){
            if(val == num) return true;
            i++;
            val = i*i;
        }
        return false;
    }
};