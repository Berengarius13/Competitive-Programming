class Solution {
public:
    bool isDigit(char ch){
        int a = ch - '0';
        if(a >= 0 && a <= 9) return true;
        return false;
    }
    int calculate(string s) {
        s.push_back('+');
        stack<char> operand;
        stack<int> stak; stak.push(0);
        char op = '+';
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(isDigit(s[i])){
                num = num * 10 + (s[i] - '0');
                continue;
            }
            if(s[i] == '('){
                operand.push(op);
                op = '+';
                stak.push(0);
            }
            
            if(s[i] == '+' || s[i] == '-' || s[i] == ')'){
                int curr = (op == '+') ? stak.top() + num : stak.top() - num;
                stak.pop();
                stak.push(curr);
                num = 0; 
                op = s[i];
            }
            if(s[i] == ')'){
                int curr = stak.top(); stak.pop();
                int temp = operand.top() == '+'? curr : -curr;
                operand.pop();
                int to_merge = stak.top(); stak.pop();
                stak.push(to_merge + temp);
            }
        }
        return stak.top();
    }
};