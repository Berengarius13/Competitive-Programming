class Solution {
public:
    bool is_digit(char ch){
        if((ch-'0')>= 0 && (ch-'0') <= 9) return true;
        return false;
    }
    int myAtoi(string s) {
        long ans = 0;
        int i = 0; 
        bool is_negative = false;
        while(s[i] == ' ') i++;
        
        if(s[i] == '-'){
            is_negative = true; i++;
        }    
        else if(s[i] == '+'){
            is_negative = false; i++;
        }
            
        while(is_digit(s[i])){
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if(is_negative){
                if((-1 * ans) < INT_MIN)
                    return INT_MIN;
            }
            else{
                if(ans > INT_MAX)
                    return INT_MAX;
            }
            i++;
        }
            
        if(is_negative)
            ans = -1 * ans;
        return ans;   
        
    }
};