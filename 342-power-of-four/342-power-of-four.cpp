class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(not(n % 10 == 4 || n % 10 == 6)) return false;
        unordered_set<int> s;
        int val = 1; s.insert(val);
        while(val <= INT_MAX/4){
            val *= 4;
            s.insert(val);
        }
        return s.find(n) != s.end();
    }
};