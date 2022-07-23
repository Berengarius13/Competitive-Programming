class Solution {
public:
    set<string> dict;
    vector<string> ans;
    
    void dfs(string &s, int begin, string temp){
        if(s.size() == begin){
            temp.pop_back();
            ans.push_back(temp);
        }
        
        string str;
        for(int i = begin; i < s.size(); i++){
            str.push_back(s[i]);
            if(dict.count(str)){
                dfs(s, i+1, temp+str+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &str : wordDict)
            dict.insert(str);
        dfs(s, 0, string());
        return ans;
    }
};