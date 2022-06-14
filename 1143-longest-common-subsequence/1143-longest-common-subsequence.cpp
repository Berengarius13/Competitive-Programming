class Solution {
public:
    int lcs(string &text1, string &text2, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == text1.size() || j == text2.size()) return 0;
        
        int a = 0; int b = 0; int c = 0;
        if(text1[i] == text2[j])
            a = 1 + lcs(text1, text2, i+1, j+1, memo);
        else{
            b = lcs(text1, text2, i+1, j, memo);
            c = lcs(text1, text2, i, j+1, memo);
        }
        memo[i][j] = max(a, max(b,c));
        return max(a, max(b,c));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size()+1, vector<int> (text2.size()+1, -1));
        return lcs(text1, text2, 0, 0, memo);
    }
};




































/*
class Solution {
public:
    int max_count = 0;
    int dfs(string &text1, string &text2, int index2, int index1,                                                            unordered_map<char,vector<int>> &mp, vector<vector<int>> &memo)
    {
        if(index2 == (text2.size()-1) || index1 == (text1.size()-1)) return 1;
     
        int maxi = 1;
        for(int i = 1 + index2; i < text2.size(); i++){
            if(mp.find(text2[i]) != mp.end()){
                for(auto &it : mp[text2[i]])
                    if(it > index1)
                        maxi = max(dfs(text1, text2, i, it, mp, memo)+1, maxi);
            }
        }
        
        return maxi;
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text2.size() > text1.size())
            text2.swap(text1);
        unordered_map<char,vector<int>> mp;
        vector<vector<int>> memo (text2.size(), vector<int> (text1.size(), -1));
        for(int i = 0; i < text1.size(); i++){ // 
            char ch = text1[i];
            if(mp.find(ch) == mp.end()){
                vector<int> temp = {i};
                mp.insert({ch, temp});
            }
            else
                mp[ch].push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < text2.size(); i++){
            if(mp.find(text2[i]) != mp.end()){
                for(auto &it : mp[text2[i]])
                    ans = max(dfs(text1, text2, i, it, mp, memo), ans);
            }
        }
        return ans;
    }
};

























/* Without Memorization
class Solution {
public:
    int max_count = 0;
    void dfs(string &text1, string &text2, int index2, int index1, int count,                                                       unordered_map<char,vector<int>> &mp)
    {
        max_count = max(count, max_count);
        
        for(int i = 1 + index2; i < text2.size(); i++){
            if(mp.find(text2[i]) != mp.end()){
                for(auto &it : mp[text2[i]])
                    if(it > index1)
                        dfs(text1, text2, i, it, count+1, mp);
            }
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text2.size() > text1.size())
            text2.swap(text1);
        unordered_map<char,vector<int>> mp;
        for(int i = 0; i < text1.size(); i++){ // 
            char ch = text1[i];
            if(mp.find(ch) == mp.end()){
                vector<int> temp = {i};
                mp.insert({ch, temp});
            }
            else
                mp[ch].push_back(i);
        }
        for(int i = 0; i < text2.size(); i++){
            if(mp.find(text2[i]) != mp.end()){
                for(auto &it : mp[text2[i]])
                    dfs(text1, text2, i, it, 1,mp);
            }
        }
        return max_count;
    }
};
*/
