class Solution {
public:
    int tribonacci(int n) {
        vector<int> m(n+3,0);
        m[0] = 0;
        m[1] = 1; 
        m[2] = 1; 
        for(int i = 3; i <= n; i++)
            m[i] = m[i-1] + m[i-2] + m[i-3];
        return m[n];
    }
};