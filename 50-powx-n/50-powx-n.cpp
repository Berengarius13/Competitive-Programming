class Solution {
public:
    double p (double x, int n){
        if(n == 0) return 1;
        double res = p (x , n/2);
        if((n&1) != 0)
            return x * res * res;
        else
            return res * res;
    }
    double myPow(double x, int n) {
        double ans = 1;
        if(n < 0)
            return (1/p(x,n));
        else
            return p(x,n);
    }
};