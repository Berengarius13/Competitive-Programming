/*
 * Same as lcs
 */
class Solution {
public:
    int lcs(string &word1, string &word2, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == word1.size() || j == word2.size()) return 0;
        
        int a = 0; int b = 0; int c = 0;
        if(word1[i] == word2[j]){
            a = 1 +lcs(word1, word2, i+1, j+1, memo);
        }
        else{
            b = lcs(word1, word2, i+1,j, memo);
            c = lcs(word1, word2, i, j+1, memo);
        }
        memo[i][j] = max(a,max(b,c));
        return max(a,max(b,c));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size()+2, vector<int> (word2.size()+2,-1));
        int longest = lcs(word1, word2, 0, 0, memo);
        int ans = word1.size() + word2.size() - 2*longest;
        return ans;
    }
};