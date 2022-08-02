class Solution {
public:
    string removeDuplicates(string s) {
        int begin = 0;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(stk.empty())
                stk.push(s[i]);
            else if(s[i] == stk.top()){
                stk.pop();
            }
            else if(s[i] != stk.top()){
                stk.push(s[i]);
            }
        }
        
        string ans;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// "ibfjcaffccadidiaidchakchchcahabhibdcejkdkfbaeeaecdjhajbkfebebfea"