class Solution {
public:
    bool isDigit(char ch){
        int a = ch - '0';
        if(a>= 0 && a <= 9) return true;
        return false;
    }
    int calculate(string s) {
        s.push_back('+');
        char op = '+';
        int num = 0;
        stack<int> stak;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            
            if(isDigit(s[i])){
                num = num * 10 + (s[i]-'0');
                continue;
            }
            else if(op == '+')
                stak.push(num);
            else if(op == '-')
                stak.push(-num);
            
            else if(op == '*' || op == '/'){
                int curr = stak.top();
                op == '*'? curr = num * curr : curr = curr/num;
                stak.pop();
                stak.push(curr);
            }
            num = 0;
            op = s[i];
        }
        int ans = 0;
        while(!stak.empty()){
            ans += stak.top();
            stak.pop();
        }
        return ans;
    }
};