class Solution {
public:
    string reverseWords(string s) {
        string ans; 
        int l = s.length()-1; 
        stack<char> stak;
        for(int i = l; i >=0; i--){
            if(s[i] == ' '){
                while(!stak.empty()){
                    ans.push_back(stak.top());
                    stak.pop();
                    if(stak.empty()) ans.push_back(' ');
                }
            }
            else{
                stak.push(s[i]);
            } 
        }
        while(!stak.empty()){
                    ans.push_back(stak.top());
                    stak.pop();
        }
        if(ans[ans.length()-1] == ' ') ans.pop_back();
            
        return ans;
    }
};