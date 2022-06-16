class Solution {
public:
    int lcs(string &s, int i, int j, vector<vector<int>> &memo){
        if(j < i) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(j == i) return 1;
        int a = 0; int b = 0; int c = 0;
        if(s[i] == s[j]){
            a = 2 +lcs(s, i+1, j-1, memo);
        }
        else{
            b = lcs(s, i+1, j, memo);
            c = lcs(s, i, j-1, memo);
        }
        memo[i][j] = max(a, max(b,c));
        return max(a, max(b,c));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int> (s.size(), -1));
        return lcs(s, 0, s.size()-1, memo);
    }
};