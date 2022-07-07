class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n > 0){
            n -= 1;
            int index = n % 26;
            char ch = index + 'A';
            ans += ch;
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};