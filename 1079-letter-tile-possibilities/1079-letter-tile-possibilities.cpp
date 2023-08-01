class Solution {
public:
    void fun(string &str, int i, unordered_set<string> &st, string &s, vector<int> &dp){
        if(i == str.size()){
            if(s.size() == 0) return;
            st.insert(s);
            return;
        }
        // not take
        fun(str, i+1, st, s, dp);
        if(dp[i] == 0){
            s.push_back(str[i]);
            dp[i] = 1;
            fun(str, 0, st, s, dp);
            dp[i] = 0;
            s.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        vector<int> dp(tiles.size(), 0);
        string s;
        fun(tiles, 0, st, s, dp);
        return st.size();
    }
};