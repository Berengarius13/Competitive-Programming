class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n -i - 1])
                return 2;
        }
        return 1;
    }
};