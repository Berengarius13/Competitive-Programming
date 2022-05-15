class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        bool ansa = true;
        bool power = false;
        int j = s.size() -1;
        int i = 0;
        while(j > i){
            if(s[i] != s[j]){
                if(s[i+1] == s[j]){
                    if(power == false){
                        i++;
                        power = true;
                        continue;
                    }
                }
                ansa = false;
                break;
            }
                i++;
                j--;
        }
        bool ansb = true;
        power = false;
        j = s.size() -1;
        i = 0;
        while(j > i){
            if(s[i] != s[j]){
                if(s[i] == s[j-1]){
                    if(power == false){
                        j--;
                        power = true;
                        continue;
                    }
                }
                ansb = false;
                break;
            }
                i++;
                j--;
        }
        
        return (ansa | ansb);
    }
};