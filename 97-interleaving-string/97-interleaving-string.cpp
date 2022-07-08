class Solution {
public:
    int lcs(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == s1.size() && j == s2.size()) return 0;
        if(k == s3.size()) return 0;
        int a = 0; int b = 0;
        if(i < s1.size() && s1[i] == s3[k])
            a = 1 + lcs(s1, s2, s3, i+1, j, k+1, memo);
        
        if(j < s2.size() && s2[j] == s3[k])
            b = 1 + lcs(s1, s2, s3, i, j+1, k+1, memo);
        
        memo[i][j] = max(a,b);
        return max(a,b);
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.size()+1, vector<int> (s2.size()+1, -1));
        int LCS = lcs(s1, s2, s3, 0, 0, 0, memo);
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        return (LCS == a + b) && (a + b == c);
    }
};