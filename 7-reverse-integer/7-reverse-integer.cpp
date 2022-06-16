class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int a = 0;
        bool flag = false;
        if(x < 0) flag = true;
        x = abs(x);
        while(x > 0){
            int lsb = x % 10;
            
            if(a > (INT_MAX/10)) return 0;
            if(a*10 > (INT_MAX-lsb)) return 0;
            a = a*10 + lsb;
            x /= 10;
        }
        if(flag) a = a*-1;
        return a;
    }
};