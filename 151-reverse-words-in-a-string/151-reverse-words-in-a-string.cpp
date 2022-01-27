class Solution {
public:
    string reverseWords(string s) {
        string ans; 
        int l = s.length()-1; 
        stack<char> stak;
        bool flag = false;
        for(int i = l; i >=0; i--){
            if(s[i] == ' '){
                while(!stak.empty()){
                    ans.push_back(stak.top());
                    stak.pop();
                    flag = true;
                }
                if (flag == true){
                    ans.push_back(' ');
                    flag = false;
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