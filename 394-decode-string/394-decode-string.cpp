/*
* Call recursion whenever you reach '['
* Return whenever you reach ']'
* Process the inside
*/
class Solution {
public:
    pair<string,int> func(string &s, int begin){
        
        string temp;
        int fre = 0;
        for(int i = begin; i < s.size(); i++){
            if(s[i] == ']') return {temp, i};
            if(isdigit(s[i])){
                fre = fre*10 + (s[i]-'0'); continue;
            }
            if(s[i] == '['){
                auto str_int = func(s, i+1);
                for(int i = 0; i < fre; i++)
                    temp += str_int.first;
                i = str_int.second;
                fre = 0;
            }
            if(s[i] != ']')
                temp += s[i];
        }
        
        return {temp, 0};
    }
    string decodeString(string s) {
        return func(s, 0).first;
    }
};