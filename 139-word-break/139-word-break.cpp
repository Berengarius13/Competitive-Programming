class Solution {
public:
    set<string> dict;
    bool mcm(string &s, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        int len = j-i+1;
        string sub  = s.substr(i, len);
        if(dict.find(sub) != dict.end()) return true;
        if(i == j) return false;
        
        bool ans = false;
        for(int k = i; k < j; k++){
            ans = (mcm(s, i, k, memo) && mcm(s, k+1, j, memo))  || ans;            
        }
        memo[i][j] = ans;
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &str : wordDict)
            dict.insert(str);
        vector<vector<int>> memo(s.size()+1, vector<int> (s.size()+1, -1));
        return mcm(s, 0, s.size()-1, memo);
    }
};