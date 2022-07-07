/*
* Pair to remember first position and if repeated or not
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = {i, 0};
            else
                mp[s[i]] = {i, 1};
        }
        int ans = INT_MAX;
        
        for(auto &[c, pari] : mp){
            if(pari.second == 0)
                ans = min(ans, pari.first);
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};