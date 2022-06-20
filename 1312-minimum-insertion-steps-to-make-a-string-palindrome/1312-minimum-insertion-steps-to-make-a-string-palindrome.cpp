// string - max palindrome length
class Solution {
public:
    int lcs(string &s, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i > j) return 0;
        if(i == j) return 1;
        
        int a = 0; int b = 0; int c = 0;
        if(s[i] == s[j]){
            a = 2 + lcs(s, i+1, j-1, memo);
        }
        else{
            b = lcs(s, i+1, j, memo);
            c = lcs(s, i, j-1, memo);
        }
        memo[i][j] = max(a, max(b,c));
        return memo[i][j];
    }
    int minInsertions(string s) {
        vector<vector<int>> memo(s.size()+1, vector<int> (s.size()+1, -1));
        int max_len = lcs(s, 0, s.size()-1, memo);
        return s.size()-max_len;
    }
};