class Solution {
public:
    vector<int> ans = {0, 0, 1}; // i, j, j-i+1 aka len
    bool lcs(string &s, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i >= j) return 1;
        
        bool a = 0;
        if(s[i] == s[j]){
            a = lcs(s, i+1, j-1, memo); // This considers case
        }
        lcs(s, i+1, j, memo);
        lcs(s, i, j-1, memo);
        
        if(a == 1 && (j-i+1) > ans[2])
            ans = {i, j, j-i+1};
        
        memo[i][j] = a;
        return a;
    }
    string longestPalindrome(string s) {
         
        vector<vector<int>> memo(s.size()+1, vector<int> (s.size()+1, -1));
        lcs(s, 0, s.size()-1, memo);
        return s.substr(ans[0], ans[2]);
    }
};