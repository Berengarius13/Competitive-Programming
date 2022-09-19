class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]] = max(mp[s[i]], i);
        }
        vector<int> ans;
        int start = 0; int i = 0;
        while(start < s.size()){
            int max_reach = mp[s[i]];
            int count = 0;
            for(i = start; i <= max_reach; i++){
                count++;
                max_reach = max(max_reach, mp[s[i]]);
            }
            ans.push_back(count);
            start = i;
        }
        return ans;
    }
};