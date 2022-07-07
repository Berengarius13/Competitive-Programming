class Solution {
public:
    int mySqrt(int x) {
        long long s = 0, e = INT_MAX, ans = 0, m;
        
        while(s <= e){
            m = s + ((e-s)>>1);
            
            if(m*m <= x){
                ans = m;
                s = m+1;
            }
            else
                e = m-1;
        }
        return ans;
    }
};













/*
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
*/