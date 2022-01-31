class Solution {
public:
    int mk(int n,vector<int> &memo)
    {     
         if(n<0) return 0;
         if(memo[n]!=-1) return memo[n];
         if(n==0) return 1;
         return memo[n]=mk(n-1,memo)+mk(n-2,memo);
    }
     
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return mk(n,memo);
    }
};
/*
wrong recursive relation is used here.
recursive but can't memorize it using 1 d;
class Solution {
public:
    int ans = 0; 
    bool canStop(int &n, int p){
        if (p == n) return 1; 
        for(int i = 1; i <= 2 && i+p<=n; i++){
            if(canStop(n, p+i)){
                ans++;
            }
        }
            return 0;
    }
    int climbStairs(int n) {
        
        canStop(n, 0);
        return ans;
    }
};
*/