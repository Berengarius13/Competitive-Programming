class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long k = 0;
        int num = x;
        while(x > 0){
            int lsb = x % 10;
            k = k*10 + lsb;
            x /= 10;
        }
        
        if(k == num) return true;
        return false;
    }
};