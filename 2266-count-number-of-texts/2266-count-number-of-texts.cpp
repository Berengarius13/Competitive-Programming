#define ll long long int
class Solution {
public:
    int countTexts(string s) {
        ll M = 1e9 + 7;
        map<char, bool> mp;
        for(char ch = '2'; ch <= '9'; ch++) mp[ch] = false;
        mp['9'] = true;
        mp['7'] = true;
        ll a = 1;
        for(int i = 0; i < s.size(); i++){
            ll ans = 0;
            int n = 1;
            char ch = s[i];
            while(i + 1 < s.size() && s[i] == s[i+1]){
                i++;
                n++;
            }
            if(mp[ch] == false){
                vector<int> dp (max(n+1, 4), 0);
                dp[1] = 1;
                dp[2] = 2;
                dp[3] = 4;
                for(int j = 4; j <= n; j++){
                    
                    dp[j] = (dp[j-1] + dp[j-2]) % M + dp[j-3];
                    dp[j] %= M;
                }
                ans = (ans % M) + dp[n];
                ans %= M;
            }
            else{
                vector<int> dp (max(n+1, 5), 0);
                dp[1] = 1;
                dp[2] = 2;
                dp[3] = 4; 
                dp[4] = 8;
                for(int j = 5; j <= n; j++){
                    dp[j] = ((dp[j-1] + dp[j-2])%M + dp[j-3])%M + dp[j-4];
                    dp[j] %= M;
                }
                ans = (ans % M) + dp[n];
                ans %= M;
            }
            a = (a % M) * (ans % M);
            a %= M;
        }
        return a;
    }
};   