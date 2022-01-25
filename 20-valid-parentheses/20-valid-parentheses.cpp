class Solution {
public:
    char is_comp(char c){
        if (c == ')')
            return '(';
        else if (c == '}')
            return '{';
        else if (c == ']')
            return '[';
        else 
            return 'a';
    }
    bool isValid(string s) {
        if((s.length())%2 != 0)
            return false;
        stack<char> stak;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == is_comp(s[i+1]))
                i++;
            else{
                if(stak.empty())
                    stak.push(s[i]);
                else{
                    if(stak.top() != is_comp(s[i]))
                        stak.push(s[i]);
                    else 
                        stak.pop();
                }
            }
        }
        if(!stak.empty())
        {if(stak.top() == is_comp(s[s.length()-1]))
            stak.pop();}
        if(stak.empty())
            return true;
        else 
            return false;
    }
};
// "([]{()[]})[{}]"
/*
*/
