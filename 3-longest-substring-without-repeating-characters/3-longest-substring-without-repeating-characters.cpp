class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int max_size = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                int temp = 0;
                int index = mp[s[i]];
                for(int k = start; k <= index; k++){
                    mp.erase(s[k]); temp=k+1;
                }
                start = temp;
            }
            mp.insert({s[i], i});
            int k = mp.size();
            max_size = max(max_size, k);
        }
        return max_size;
    }
};