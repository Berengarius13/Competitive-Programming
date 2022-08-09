class Solution {
public:
    vector<int> ans = {0, 0, 1};
    bool lcs(string &s, int i, int j, vector<vector<int>> &memo){
        if(i > j) return 1;

        if(memo[i][j] != -1) return memo[i][j];
        bool a = 0;
        if(s[i] == s[j]){
            a = 1 && lcs(s, i+1, j-1, memo);
        }
        
        lcs(s, i+1, j, memo);
        lcs(s, i, j-1, memo);
        if(a){
            int len = j-i+1;
            if(len > ans[2]){
                ans[0] = i; ans[1] = j; ans[2] = len;
            }
        }
        
        return memo[i][j] = a;
            
    }
    string longestPalindrome(string s) {
        vector<vector<int>> memo(s.size() +1, vector<int> (s.size()+1, -1));
        lcs(s, 0, s.size()-1, memo);
        return s.substr(ans[0], ans[2]);
    }
};