class Solution {
public:
    double ans = 1;
    double dfs(double x, long exp, double a, long n, double ini){
        if(n == 0){
            ans = a*x/ini;
            return 1;
        }
        if(exp*2 > n){
            dfs(ini, 1, a*x, n-exp, ini);
        }
        else{
            dfs(x*x, exp*2, a, n, ini);
        }
        return 1;
    }
    double myPow(double x, int n) {
        if(x == 0 && n == 0) return 1;
        if(x == 0) return 0;
        if(n < 0){
            n = abs(n);
            x = 1/x;
        }
        dfs(x, 1, 1, n, x);
        return ans;
    }
};