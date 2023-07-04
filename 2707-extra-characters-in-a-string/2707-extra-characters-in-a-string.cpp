class Solution {
public:
    int fun(string &s, int i, int j, vector<vector<bool>> &present, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(present[i][j]) return 0;
        if(i == j) return 1;
        int mn = INT_MAX;
        for(int k = i; k + 1 <= j; k++){
            int a = fun(s, i, k, present, dp);
            int b = fun(s, k+1, j, present, dp);
            mn = min(mn, a+b);
        }
        return dp[i][j] = mn;
    }
    int minExtraChar(string s, vector<string>& dict) {
         vector<vector<bool>> present(s.size(), vector<bool> (s.size(), 0));
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
         unordered_set<string> st;
         for(auto &c: dict){
             st.insert(c);
         }
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(st.find(s.substr(i, j-i+1)) != st.end()){
                    present[i][j] = true;
                }
            }
        }
        return fun(s, 0, s.size()-1, present, dp);
    }
};