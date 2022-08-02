class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> count; 
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(!count.empty() && count.top() == k){
                int ct = count.top(); count.pop();
                while(ct){
                    stk.pop(); ct--;
                }
            }
            
            if(stk.empty() || stk.top() != s[i]){
                stk.push(s[i]);
                count.push(1);
            }
            else if (stk.top() == s[i]){
                stk.push(s[i]);
                int ct = count.top(); count.pop();
                count.push(++ct);
            }
        }
        if(!count.empty() && count.top() == k){
                int ct = count.top(); count.pop();
                while(ct){
                    stk.pop(); ct--;
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