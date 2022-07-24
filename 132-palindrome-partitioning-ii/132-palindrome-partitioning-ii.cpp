class Solution {
public:
    bool is_palindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int mcm(string &s, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(is_palindrome(i, j, s) || i>=j) return 0;
        
        int maxi = INT_MAX;
        for(int k = i; k < j; k++){
            if(is_palindrome(i, k, s)){                         
                int temp = mcm(s, k+1, j, memo) + 1;
                maxi = min (maxi, temp);
            }
        }
        memo[i][j] = maxi;
        return maxi;
    }
    int minCut(string s) {
        vector<vector<int>> memo(s.size()+1, vector<int> (s.size()+1, -1));
        return mcm(s, 0, s.size()-1, memo);
    }
};