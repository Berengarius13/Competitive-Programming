/*
* Same as longest palindoromic substring
* To avoide duplicates make set 
*/
class Solution {
public:
     set<pair<int,int>> mp;
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
            if(mp.find({i,j}) == mp.end())
                mp.insert({i,j});
        }
        return memo[i][j] = a;
            
     }
    int countSubstrings(string s) {
        vector<vector<int>> memo(s.size() +1, vector<int> (s.size()+1, -1));
        lcs(s, 0, s.size()-1, memo);
        return mp.size();
    }
};