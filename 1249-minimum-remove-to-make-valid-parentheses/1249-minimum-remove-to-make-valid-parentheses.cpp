class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        unordered_set<int> st;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                stk.push(i);
            }
            else if(ch == ')'){
                if(stk.size() == 0){
                    st.insert(i);
                }
                else stk.pop();
            }
        }
        while(!stk.empty()){
            st.insert(stk.top());
            stk.pop();
        }
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(st.find(i) == st.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};