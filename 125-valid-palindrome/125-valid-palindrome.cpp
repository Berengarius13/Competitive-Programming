
class Solution {
public:
    char asciitolower(char in) {
        if (in <= 'Z' && in >= 'A')
            return in - ('Z' - 'z');
        return in;
        }
    bool isPalindrome(string s) {
        bool ans = true;
        string temp;
        int i =0; 
        int j = s.length()-1;
        while(i<=j){
            if(((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<= 90) || (s[i]>=97 &&  s[i]<=122))){
                temp.push_back(s[i]);
            }
         i++;
        }
        // i = s.length()-1;
        // for(i = s.length()-1; i>=0; i--){
        //     if(!((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<= 90) || (s[i]>=97 &&  s[i]<=122))){
        //         s.pop_back();
        //     }
        // }
        i= 0;
        for(i = 0; i < temp.length(); i++){
            temp[i] = asciitolower(temp[i]);
        }
        i = 0;
        for(i = 0; i< temp.length(); i++){
            if(temp[i] != temp[temp.length()-i-1]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};