class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ma;
        unordered_map<char, int> mb;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            ma[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            mb[t[i]]++;
        }
        bool ans = true;
        for(int i = 0; i < s.size(); i++){
            if(ma[s[i]] == mb[s[i]])
                ans = true;
            else 
                return false;
        }
        return ans;
    }
};