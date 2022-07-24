/*
* Like word break 2
* Dfs begin type
* Build string along the way and do operations
*/
class Solution {
public:
    vector<vector<string>> ans;
    bool is_palindrome(string &s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp;
    }
    void dfs(string &s, int begin, vector<string> &temp){
        if(s.size() == begin)
            ans.push_back(temp);
        
        string str;
        for(int i = begin; i < s.size(); i++){
            str.push_back(s[i]);
            if(is_palindrome(str)){
                temp.push_back(str);
                dfs(s, i+1, temp);
                temp.pop_back();
            }
        }
            
    }
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        dfs(s, 0, vec);
        return ans;
    }
};